#include "libmx.h"

char **mx_read_args(char **str, int size) {
    char **result = malloc((size + 1)*sizeof(char*));
    int line = 0, num = 0;
    result[size] = NULL;

    if (size < 2)
        mx_printerrmess(INVALID_NUM_ISLANDS, NULL);
    for (; line < size; line++)
        result[line] = "";
    for (line = 1; str[line] != NULL; line++)
        if (mx_linechecker(str[line], line)) {
            if (num > size)
                mx_printerrmess(INVALID_NUM_ISLANDS, NULL);
            mx_start_isld(str[line], result, &num);
            if (num > size)
                mx_printerrmess(INVALID_NUM_ISLANDS, NULL);
            mx_finish_isld(str[line], result, &num);
        }
    if (num != size)
        mx_printerrmess(INVALID_NUM_ISLANDS, NULL);
    return result;
}
