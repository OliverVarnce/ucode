#include "libmx.h"

void* mx_memset(void *dest, int c, size_t count) {
    char* p = (char*)dest;
   
    while (count-- > 0) 
        *p++ = c;
    
    return dest;
}
