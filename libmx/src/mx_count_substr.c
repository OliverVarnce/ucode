#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub)
		return -1;
    
    int res = 0, 
    substr_len = mx_strlen(sub);

	for (str = mx_strstr(str, sub); str && *sub; res++)
		str = mx_strstr(str + substr_len, sub);
	return res;
}
