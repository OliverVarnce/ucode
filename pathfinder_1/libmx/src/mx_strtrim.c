#include "libmx.h"

char *mx_strtrim(const char *str){
    size_t	i = 0;
	size_t	j;

	if (!str)
		return NULL;

	while (mx_isspace(str[i]) && str[i])
		i++;

	j = mx_strlen(str + i) - 1;

	while (str[i] && mx_isspace(str[j + i]))
		j--;

	return (mx_strsub(str, i, j + 1));
}
