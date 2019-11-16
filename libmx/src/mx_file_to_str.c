#include "libmx.h"

char *mx_file_to_str(const char *file){
    int fd = open(file, O_RDONLY);
	int len = 0;
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
			len++;
		}
		close(fd);
		fd = open(file, O_RDONLY);
		retstr = mx_strnew(len);
		while (read(fd, &buf, 1)) {
			retstr[i] = buf;
			i++;
		}
		close(fd);
		return retstr;
	}
}
