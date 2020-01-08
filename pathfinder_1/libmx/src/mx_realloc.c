#include "libmx.h"

size_t mx_getsize(void * p) {
    size_t *in = p;
    if (in) { 
        --in;
        return *in; 
    }
    return -1;
}


void *mx_realloc(void *ptr, size_t size) {
    void *newptr;
    size_t msize = mx_getsize(ptr);

    if (size <= msize)
        return ptr;
    newptr = malloc(size);
    mx_memcpy(newptr, ptr, msize);
    free(ptr);
    return newptr;
}


int main() {
    char *str1 = malloc(15 * sizeof(char));
    str1 = mx_strcpy(str1, "tutorialspoint");
    printf("%s\n", str1);
    str1 = mx_realloc(str1, 4);
    str1 = mx_strcat(str1, ".com");
    printf("%s\n", str1);
    return 0;
}
