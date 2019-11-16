#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	char *newstr = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

	if (!s1 && !s2)
		return NULL;
	
	if (!s1 || !s2){
		if (s1)
			return mx_strdup(s1);
		else
			return mx_strdup(s2);
		}
	
	if (newstr) {
		mx_strcpy(newstr, s1);
		mx_strcat(newstr, s2);
	}	
	
	return newstr;
}
