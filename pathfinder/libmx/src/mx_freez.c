#include "libmx.h"

char *mx_freez(int buf_size, char delim, const int fd) {
    char *tmp = NULL;
    char *rr_str = NULL;
    char buffer[buf_size + 1];
    int read_res = 0;
    int delim_index;

    while ((read_res = read(fd, buffer, buf_size)) > 0) {
        buffer[read_res] = '\0';
        tmp = mx_strjoin(rr_str, buffer);
        mx_strdel(&rr_str);
        rr_str = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(rr_str, delim);
        if (delim_index >= 0)
            break;
    }

    return rr_str;
}
