#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){     
    char *s = (char *)src;
    char *d = (char *)dst;
    char *ptr;
    size_t i;

    for(i = 0; i < n; i++) {
        d[i] = s[i];
       
        d[i+1] = '\0';  
        if (s[i] == c) {
            ptr = &d[i + 1];
            return ptr;
        }
    }
    return 0;
}


/*int main() {
    char *src = "wakafloka";
    char *src2 = "wakafloka";
    char dst[11];
    char dst2[11];
    mx_memccpy(dst, src, 'f', 10);
    printf("%s\n",dst);
    memccpy(dst2, src2, 'f', 10);
    printf("%s\n",dst2);
}*/
