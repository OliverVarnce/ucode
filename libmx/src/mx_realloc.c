#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *res = NULL;

    if (!ptr && size)
        return malloc(size);

    if (ptr && !size) {
        free(ptr);
        res = malloc(malloc_size(NULL));
        mx_memcpy(res,"", 16);
        return res;
    }

    res = malloc(size);
    mx_memcpy(res, ptr, malloc_size(ptr));
    free(ptr);
    return res;
}
