#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	
	if (!sub || !replace || !str)
		return NULL;

	char *result;
	int i, count = 0;

	int slen = mx_strlen(sub);
	if (slen == 0) {
		return NULL;
	}
	int rl = mx_strlen(replace);

	for (i = 0; str[i] !='\0' ; i++) {
		if (mx_strstr(&str[i], sub) == &str[i]) {
			count++;
			i += slen - 1; 
		}
	}

	result = mx_strnew(i + count * (rl - slen) + 1);

    i = 0;

	while(*str) {
		if(mx_strstr(str, sub) == str) {
			mx_strcpy(&result[i], replace);
			i += rl;
			str += slen;
		}
		else {
			result[i++] = *str++;
		}
	}
	result[i] = '\0';
	return result;
}
