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

/*int main(){
    char src[5] = "fackk";
    char dst[4]= "1111";
    char *res = mx_strncpy(dst, src, 4);
    //printf("%s\n", mx_strncpy(dst, src, 3));
    printf("%s\n", res);
    return 0;
}*/
