#pragma once
#include "CMemoryPoolItem.h"

class CFullPath :
	public CMemoryPoolItem
{
	wchar_t					*m_FullPath;
	const static size_t		m_MaxPathLength = 32768;
public:
	CFullPath();
	virtual ~CFullPath();

	void InitializePath(wchar_t *FullPath);

	// TODO: Add any path handling functions to the class here.
};

