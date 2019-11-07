#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    if(!n){
        return 0;
    }

    while (--n && *(char *)s1 == *(char *)s2){
        s1 = (char *)s1 + 1;
        s2 = (char *)s2 + 1;
    }

    return(*((unsigned char*)s1) - *((unsigned char*)s2));
}

/*int main() {
    unsigned char src[15]="1234567890";
    unsigned char dst[15]="1234567890";

   // Сравниваем первые 10 байт массивов
   // и результат выводим на экран
   printf("%d\n", mx_memcmp(src, dst, 10));
   printf("%d", memcmp(src, dst, 10));
   return 0;
}*/
