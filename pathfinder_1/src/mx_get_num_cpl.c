#include "libmx.h"

int mx_get_num_cpl(char *isl) {
    int i = mx_get_char_index(isl, ',') + 1;
    return mx_atoi(&isl[i]);
}
