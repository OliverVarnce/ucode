#include "libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (!s)
        return NULL;

    int cnt = mx_count_words(s--, c), i = 0;
    char *tonxt;
    char **p = malloc((cnt + 1) * sizeof(char *)); 
    
    if (!p)
        return NULL;
    p[cnt] = NULL;
    while (*(++s))
        if (((tonxt = mx_strchr(s, c)) || 
        (tonxt = mx_strchr(s, '\0'))) && *s != c && 
        (p[i++] = mx_strndup(s, tonxt - s)) && 
        (s = tonxt) && !(*s))
            return p;
    return p;
}
