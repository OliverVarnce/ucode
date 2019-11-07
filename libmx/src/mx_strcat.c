#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int l1 = mx_strlen(s1);
    int i;

    for (i = 0; s1[i] != '\0'; i++)
        s1[l1 + i] = s2[i];
    return s1;
}
