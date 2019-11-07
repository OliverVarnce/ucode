#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) { 
    const unsigned char *haystack = (const unsigned char *) big;
    const unsigned char *needle = (const unsigned char *) little;
    const unsigned char *h = NULL;
    const unsigned char *n = NULL;
    size_t x = little_len;

    if (little_len == 0)
        return (void *) big;

    if (big_len < little_len)
        return NULL;

    for (; *haystack && big_len--; haystack++) {
        x = little_len;
        n = needle;
        h = haystack;

        if (big_len < little_len)
            break;

        if ((*haystack != *needle) || ( *haystack + little_len != *needle + little_len))
            continue;

        for (; x ; h++ , n++) {
            x--;

            if (*h != *n) 
                break;

            if (x == 0)
               return (void *)haystack;
        }
    }
       return NULL;
}

/*int main()
{
    const char str[]= "This is a strstr test";
    const char search[]= "strstr";

    const char *result = mx_memmem(str, mx_strlen(str), search, mx_strlen(search));
    const char *result2 = memmem(str, mx_strlen(str), search, mx_strlen(search));

    if ( result )
       printf("original: %s\n\n item: %s\n found: %s\n", str, search, result);

    if ( result2 )
       printf("\n\nGcc Lib memmem!\n original: %s\n item: %s\n found: %s\n", str, search, result2);
}*/
