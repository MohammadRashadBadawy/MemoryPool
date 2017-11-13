#include "CFullPathMemoryPoolManager.h"
#include "CFullPath.h"



CFullPathMemoryPoolManager::CFullPathMemoryPoolManager()
{
}


CFullPathMemoryPoolManager::~CFullPathMemoryPoolManager()
{
}

CMemoryPoolItem* CFullPathMemoryPoolManager::AllocateMemoryPoolItem()
{
	CFullPath*	FullPath = nullptr;

	FullPath = new CFullPath();

	if (FullPath == nullptr)
		throw exception("Not enough memory to allocate CFullPath in the memory pool");
	return FullPath;
}
