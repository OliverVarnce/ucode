#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    char *d_ptr, *s_ptr;
    size_t i;
    int delta;

    if (dst < src){
        d_ptr=(char*)dst;
            s_ptr=(char*)src;
            delta = 1;
        }
        else if (dst >src){
            d_ptr=(char*)dst + len -1;
            s_ptr=(char*)src + len - 1;
            delta = -1;
        }
        else{
            return dst;
        }

        for(i = 0; i < len; ++i){
            *d_ptr=*s_ptr;
            d_ptr+=delta;
            s_ptr+=delta;
        }
        return dst;
}

