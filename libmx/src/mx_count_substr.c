#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0, count1 = 0;
    int i, j, l1, l2;

    if (str == NULL || sub == NULL)
        return -1;
    
    l1 = mx_strlen(str);
    l2 = mx_strlen(sub);

    for (i = 0; i < l1;) {
        j = 0;
        count = 0;
        while ((str[i] == sub[j])) {
            count++;
            i++;
            j++;
        }
        if (count == l2) {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    } 
return count1;
}
