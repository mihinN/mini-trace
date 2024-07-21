** Simple syscall decoder ** 

If something like 'libraryError' is shown, indicating a missing library such as `#include <bits/libc-header-start.h>`, 
it is because the code is being compiled into 32-bit binaries (using the `-m32` flag). 
Therefore, you need to install the `gcc-multilib` library.
