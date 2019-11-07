#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
    if(s1 == NULL)
        return NULL;

    char *res = malloc(mx_strlen(s1) * sizeof(char));

    if (res == NULL)
        return NULL;

    return mx_strncpy(res, s1, n);

}

/*int main() {
    const char *str = "fuck U";
    printf("%s", mx_strndup(str, 3));
    return 0;
}*/
