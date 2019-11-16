#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){
    if (n == 0)
		return NULL;
            
    unsigned char *s = (unsigned char *)src;
    unsigned char *d = (unsigned char *)dst;
    

    for(size_t i = 0; i < n && d[i] != c; i++) {
        d[i] = s[i];
       
        if (s[i] == c) {
            d[i] = s[i];
            return &d[i + 1];
        }
    }
    return NULL;
}
