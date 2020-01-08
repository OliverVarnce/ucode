#include "libmx.h"

void* mx_memset(void *dest, int c, size_t count) {
    char* p = (char*)dest;
   
    while (count-- > 0) 
        *p++ = c;
    
    return dest;
}

/*int main() {
    int a[5]={5,6,7,8,9};
    int size =5;
    int d= '3';

    //mx_memset(a,d,size);
    //printf("%d\n", d);
    memset(a,d,size);
    printf("%d\n", d);

}*/
