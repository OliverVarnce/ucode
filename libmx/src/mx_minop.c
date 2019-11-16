#include "libmx.h"

size_t mx_minop(size_t s1, size_t s2){
    if ((s1 < s2))
        return s1;
    return s2;
}
