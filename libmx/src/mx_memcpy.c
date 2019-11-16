#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *s1=(char*)dst;
    char *s2=(char*)src;

   for (; n-- > 0; s1++, s2++)
		*s1 = *s2;
	return dst;
}
