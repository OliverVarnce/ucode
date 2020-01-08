#include "libmx.h"

bool mx_isdigit(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    else {
        return 0;
    }
}
