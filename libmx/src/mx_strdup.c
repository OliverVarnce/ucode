#include "libmx.h"

char *mx_strdup(const char *str) {
	char *dst;
	int len = 0;
	

	len = mx_strlen(str);
	dst = mx_strnew(len);
	dst = mx_strcpy(dst, str);
	return dst;

}
