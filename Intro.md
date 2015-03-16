# Introduction #

When I have needed to store large datasets, statical data or metering data, I often use an external disk. While doing so it seemed excessive to format a disk on some fancy file system so that I can store a single file on it. Thus I decided to on occasion use raw disk, but even then I noticed the need to divide the disk into smaller blocks, and to keep books of which blocks are occupying data and which are free, and further it came in handy to be able to find the first free block. For this purpose the Van Emde Boas tree is perfect.

The implementation presented here does so by storing the data in a single byte array. I can then store and load the tree from the first sector on the disk and divide the rest into blocks. Of course what is more difficult is to allocate several consecutive blocks, however for the intended purpose this structure is optimal. Even if we were to consider the standard proposed space optimisation to van Emde Boas structures, namely only allocating the used sub-trees, the unused block are still physically present on the disk.


# On the Implementation #

I believe the code needs to be clean and short. The actual code takes less than 400 lines of C code -I have seen people write single functions longer than this. The only data structure defined, Veb, gives a pointer to the byte array containing the actual van Emde Boas tree, and the number of elements it can hold, and the number of bits needed to store the largest element, which in is in fact the square root of the number of elements but for convenience it is transferred around, also because it is not certain that calculating this number is a cheap operation.

The unit tests are written in the simplest possible way, i.e., they are Unix executables returning zero on success and something else on failure. For some reason people need entire libraries, such as JUnit etc. to write test cases. It seems uncalled and unnecessary. The unit test framework here consists of a single macro and a single short shell-script, besides the tests themselves.