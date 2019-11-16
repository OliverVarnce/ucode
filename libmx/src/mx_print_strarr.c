#include "libmx.h"
#include <stdio.h>

void mx_print_strarr(char **arr, const char *delim){
     if (!delim || !arr || !*arr)
        return;
    
    while (*arr) {
        mx_printstr(*arr);
        if (*(arr+1))
            mx_printstr(delim);
        arr++;
    }
    mx_printchar('\n');
}
