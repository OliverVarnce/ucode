#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *lgs = NULL;
    char buffer[buf_size + 1];
    int readbytes = 0, index_delim = -1;
    char *t_str = NULL, *tmp = NULL;

    if(lgs)
        t_str = mx_strdup(lgs);

    if (!lineptr)
		return -2;
	mx_strdel(lineptr);

    while ((readbytes = read(fd, buffer, buf_size)) >= 0) {
        buffer[readbytes] = '\0';
        tmp = mx_strjoin(t_str, buffer);
        mx_strdel(&t_str);
        t_str = mx_strdup(tmp);
        mx_strdel(&tmp);
        
        index_delim = mx_get_char_index(t_str, delim);

        if (index_delim != -1){
            t_str[index_delim] = '\0';
            if(lgs)
                mx_strdel(&lgs);
            lgs = mx_strdup(t_str + index_delim + 1);
            break;
        }

        if (readbytes == 0) {
            if (lgs)
                mx_strdel(&lgs);
            break;
        } 
    }

    if (readbytes == -1)
        return -1;

    *lineptr = mx_strdup(t_str);
    mx_strdel(&t_str);
    return mx_strlen(*lineptr);
}
