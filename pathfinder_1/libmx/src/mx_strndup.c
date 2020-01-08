#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned long len = mx_strlen(s1);
    
    if (len > n)
        len = n;
    return mx_strncpy(mx_strnew(len), s1, len);
}

/*int main() {
    const char *str = "fuck U";
    printf("%s", mx_strndup(str, 3));
    return 0;
}*/
