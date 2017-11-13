# MemoryPool
Base classes that implements thread safe memory pool (object pool) design pattern, with example children classes. It can be used by applications that allocates huge number of objects from the same class, in which each object has a maximum known size. This memory pool enhance the performance of the application by avoid allocation and de-allocation of memory many many number of times, and also avoid memory fragmentation problem.
CMemoryPoolItem is the base class for any object that needs to be managed in a memory pool. Any class can inherit this base class to allow its objects to be managed by the memory pool manager.
CFullPathMemoryPoolManager is the base class of the memory pool manager. This class must be inherited and the child class must implement its AllocateMemoryPoolItem method to instantiate an object from the class that inherits from CMemoryPoolItem.
An example for using these base classes is implemented by CFullPath and CFullPathMemoryPoolManager children classes. It assumes that the application that will use this memory pool is processing a huge number of files and directories, which requires allocating and de-allocating a huge number of buffers in heap that hold the full path name of each processed file and directory. It is known that the maximum UNC full path name is 32768 characters length, so the child class CFullPath allocates a buffer of length 32768 wide characters. Additional methods can be added to the CFullPath class to implements the required processing on the full path string. The CFullPathMemoryPoolManager class implements AllocateMemoryPoolItem of its base class to allocate CFullPath object.
