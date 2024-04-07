** Simple syscall decoder ** 

* If something like 'libraryError' is shown, a missing library such as 
'#include <bits/libc-header-start.h>', it's because the code will compile into 32-bit binaries (-m32). 
so, you need to install the 'gcc-multilib' library.