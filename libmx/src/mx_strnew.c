#include "libmx.h"

char *mx_strnew(const int size){
	if (size < 0)
        return NULL;

	char *buffer = (char *) malloc(sizeof(char) * (size + 1));

	if (buffer == NULL) {
		return NULL;
	}
		
	for (int i = 0; i <= size; i++){
		buffer[i] = '\0';
	}
	
	return buffer;
}
