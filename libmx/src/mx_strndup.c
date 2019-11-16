#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
    if(s1 == NULL)
        return NULL;

    char *res = malloc(mx_strlen(s1) * sizeof(char) + 1);

    if (res){
        res[n] = '\0';
        while (n-- > 0)
			res[n] = s1[n];
    }
    
    return res;
}


