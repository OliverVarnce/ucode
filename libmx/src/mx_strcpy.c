#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
	int i = 0;
	char *s = dst;	

	if(dst == NULL)
		return NULL;

	while ((dst[i] = src[i]) != '\0')
	{
		i++;
	}
	return s;
}

/*int main(){
    char src[5] = "fackk";
    char dst[4]= "1111";
    char *res = mx_strncpy(dst, src);
    //printf("%s\n", mx_strcpy(dst, src));
    printf("%s\n", res);
    return 0;
}*/
