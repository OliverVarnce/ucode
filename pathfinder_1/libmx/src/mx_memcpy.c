#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *s1=(char*)dst;
    char *s2=(char*)src;

    for (size_t i = 0; i < n; i++)
        *s1++ = *s2++;
    return s1;
}

/*int main()
{
    char temp[]="simple";
    printf("%s",(char*)mx_memcpy(temp,"abcde",3));
 
}*/
