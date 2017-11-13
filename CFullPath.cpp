#include "CFullPath.h"
#include <stdexcept>

using namespace std;


CFullPath::CFullPath()
{
	// Allocate a buffer that holds the maximum allowed path length, including NULL terminator.
	m_FullPath = (wchar_t*)malloc(m_MaxPathLength * sizeof(wchar_t));

	if (m_FullPath == nullptr)
		throw exception("Not enough memory to allocate m_FullPath inside CFullPath constrcutor");
}


CFullPath::~CFullPath()
{
	if (m_FullPath != nullptr)
		free(m_FullPath);
}

void CFullPath::InitializePath(wchar_t * FullPath)
{
	// Validate input parameter.
	if (FullPath == nullptr)
		throw invalid_argument("Invalid argument (NULL FullPath parameter) passed to CFullPath constrcutor");

	// Throw exception, if the given path was larger than the maximum allowed path length (including NULL terminator).
	if (wcslen(FullPath) >= m_MaxPathLength)
		throw length_error("The length of FullPath parameter is larger than the maximum allowed path length");

	// TODO: Add any validation to the path format here.

	// Initialize the full path member variable.
	wcsncpy_s(m_FullPath, m_MaxPathLength, FullPath, m_MaxPathLength);
}
