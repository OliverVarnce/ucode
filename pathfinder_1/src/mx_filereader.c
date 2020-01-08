#include "libmx.h"

char **mx_filereader(char **argv) {
    char *str, **file;

    str = mx_file_to_str(argv[1]);
    if (str == NULL)
        mx_printerrmess(FILE_DNT_EXIST, argv[1]);
    if (mx_strlen(str) == 0)
        mx_printerrmess(FILE_EMPTY, argv[1]);
    file = mx_strsplit(str, '\n');
    free(str);
    return file;
}
