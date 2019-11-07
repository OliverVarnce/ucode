#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle){
    size_t	i;

	if (!*needle)
		return ((char *)haystack);
	
    while (*haystack) {
		i = 0;
		
        while (*(needle + i) && *(needle + i) == *(haystack + i))
			i++;
		
        if (!*(needle + i))
			return ((char *)haystack);
		haystack++;
	}
	return NULL;
}
