#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *lgs[4096];
    char *tmp = mx_strjoin(lgs[fd], tmp);
    int delim_index = mx_get_char_index(tmp, delim);


    if (buf_size <= 0 || read(fd, 0, 0) < 0 || fd < 0 || fd > 4096)
        return -1;

    char *llgsL = mx_freez(buf_size, delim, fd);
    if (!llgsL)
        return 0;

    tmp[delim_index] = '\0';
    lgs[fd] = mx_strdup(tmp + delim_index + 1);
    *lineptr = mx_strdup(tmp);
    mx_strdel(&tmp);
    return mx_strlen(*lineptr);
}

/*int main() {
	char *file = "fragment";
	int fd = open(file, O_RDONLY);
	char *str = "er a fire licked its way across\n the polyester carpeting, destroying several rooms as it\n spooled soot up the walls and ceiling, leaving patterns of\n permanent shadow";

	char res = mx_read_line(&str, 20, 'f', fd); //res = 25, str = "The hotel was abandoned a"
	printf("%d\n", res);
	return 0;
}*/
