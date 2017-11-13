#include "CMemoryPoolManager.h"

CMemoryPoolManager::CMemoryPoolManager()
{
	InitializeCriticalSection(&m_ItemsProtector);
}


CMemoryPoolManager::~CMemoryPoolManager()
{
	ItemListIter	it;

	// Deallocate the memory used in the memory pool items.
	EnterCriticalSection(&m_ItemsProtector);

	for (it = m_ItemsList.begin(); it != m_ItemsList.end(); ++it)
		delete *it;
	m_ItemsList.clear();

	LeaveCriticalSection(&m_ItemsProtector);

	DeleteCriticalSection(&m_ItemsProtector);
}

CMemoryPoolItem* CMemoryPoolManager::GetItem()
{
	CMemoryPoolItem*	Item = nullptr;

	EnterCriticalSection(&m_ItemsProtector);

	// If there is not any available item in the memory pool, then instantiate a new one and return it to the caller.
	if (m_ItemsList.size() == 0)
	{
		Item = AllocateMemoryPoolItem();

		// Throw an exception, if the memory is full and couldn't allocate a new item.
		if (Item == nullptr)
		{
			LeaveCriticalSection(&m_ItemsProtector);
			throw exception("Not enough memory to allocate CMemoryPoolItem in the memory pool");
		}
	}
	// ELSE: If the memory pool has available item(s), then get one and return it to the caller.
	else
	{
		Item = m_ItemsList.front();
		m_ItemsList.pop_front();
	}
	LeaveCriticalSection(&m_ItemsProtector);

	return Item;
}

void CMemoryPoolManager::ReleaseItem(CMemoryPoolItem* Item)
{
	EnterCriticalSection(&m_ItemsProtector);

#ifdef _DEBUG
	// Just for debugging purpose, make sure that we don't release the same object twice.
	// For better performance, we should not loop through the entire list every time we release an object, and the caller is responsible for
	// not releasing the same object twice. That's why I'm doing this validation in debug mode only.
	ItemListIter	it;
	bool			AlreadyExists = false;

	for (it = m_ItemsList.begin(); it != m_ItemsList.end(); ++it)
	{
		if (Item == *it)
			AlreadyExists = true;
	}

	if (!AlreadyExists)
#endif
		m_ItemsList.push_back(Item);
	LeaveCriticalSection(&m_ItemsProtector);
}
