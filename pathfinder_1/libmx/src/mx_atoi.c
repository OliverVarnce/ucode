#include "libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int n = 0;
    int s = 1;

    for (; mx_isspace(str[i]); i++);
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            s = -1;
        i++;
    }
    for (; mx_isdigit(str[i]); i++) { 
        n = n * 10 + (str[i] - 48) * s;
    }
    return n;
}
