#include "libmx.h"
//#include<string.h>

char *mx_strncpy(char *dst, const char *src, int len){
    int i;
    char *temp = dst;  

    if(dst == NULL)
		return NULL;
   
    for (i = 0; i < len; i++)
        *dst++ = *src++;
    return temp;
}

