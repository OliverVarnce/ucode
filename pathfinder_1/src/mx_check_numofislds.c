#include "libmx.h"

void mx_check_numofislds(char *str) {
    while (*str != '\0') {
        if (mx_isdigit(*str))
            str++;
        else
            mx_printerrmess(INVALID_FIRST_LINE, NULL);
    }
}
