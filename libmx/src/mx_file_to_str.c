#include "libmx.h"

char *mx_file_to_str(const char *file){
    int fd = open(file, O_RDONLY);
	int stlen = 0;
	int i = 0;
	char buf;
	char *retstr;

	if (read(fd, (void *)0, 0) < 0) {
		return 0;
	}
	else if (fd == -1) {
		return 0;
	}
	else {
		while (read(fd, &buf, 1)) {
			stlen++;
		}
		close(fd);
		fd = open(file, O_RDONLY);
		retstr = mx_strnew(stlen);
		while (read(fd, &buf, 1)) {
			retstr[i] = buf;
			i++;
		}
		return retstr;
	}
}
