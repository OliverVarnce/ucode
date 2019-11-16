#include "libmx.h"

char *mx_del_extra_spaces(const char *str){
    if (!str || str == NULL)
        return NULL;

    char str_len = mx_strlen(str), 
    *st = mx_strnew(str_len), 
    *res;
    if (st)
        for (int i = 0; *str; st[i++] = *(str++))
            if (mx_isspace(*str)){
                for (st[i++] = ' '; mx_isspace(*str); ++str);
                if (!(*str))
                    break;
            }
    res = mx_strtrim(st);
    free(st);
    return res;
   
}
