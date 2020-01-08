#include "libmx.h"

bool mx_linechecker(char *str, int line) {
    char *l = mx_itoa(line);
    
    while (*str != '-')
        if (mx_isalpha(*str))
            str++;
        else
            mx_printerrmess(INVALID_LINE, l);
    str++;
    while (*str != ',')
        if (mx_isalpha(*str))
            str++;
        else
            mx_printerrmess(INVALID_LINE, l);
    str++;
    while (*str != '\0')
        if (mx_isdigit(*str))
            str++;
        else 
            mx_printerrmess(INVALID_LINE, l);
    return true;
}
