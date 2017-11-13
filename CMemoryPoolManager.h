#pragma once
#include <Windows.h>
#include <list>
#include "CMemoryPoolItem.h"

using namespace std;

typedef list<CMemoryPoolItem*>	ItemList;
typedef ItemList::iterator		ItemListIter;

class CMemoryPoolManager
{
	CRITICAL_SECTION	m_ItemsProtector;
	ItemList			m_ItemsList;
public:
	CMemoryPoolManager();
	virtual ~CMemoryPoolManager();

	CMemoryPoolItem* GetItem();
	void ReleaseItem(CMemoryPoolItem *MemoryPoolItem);

protected:
	virtual CMemoryPoolItem* AllocateMemoryPoolItem() = 0;
};

