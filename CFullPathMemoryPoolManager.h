#pragma once
#include "CMemoryPoolManager.h"
class CFullPathMemoryPoolManager :
	public CMemoryPoolManager
{
public:
	CFullPathMemoryPoolManager();
	virtual ~CFullPathMemoryPoolManager();

protected:
	virtual CMemoryPoolItem* AllocateMemoryPoolItem();
};

