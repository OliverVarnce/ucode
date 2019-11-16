#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (sub == NULL || str == NULL)
        return  -2;
    
    
    char *result = mx_strstr(str, sub);
    int position = result - str;

    if (result == NULL)
        position =  -1;
   

    return position;
}
