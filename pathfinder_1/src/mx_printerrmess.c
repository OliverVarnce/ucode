#include "libmx.h"

void mx_printerrmess(t_error err, const char *comment) {
switch (err) {
        case INVALID_ARGS:
            mx_printerror("usage: ./pathfinder [filename]");
            break;
        case FILE_DNT_EXIST:
            mx_printerror("error: file ");
            mx_printerror(comment);
            mx_printerror(" does not exist");
            break;
        case FILE_EMPTY:
            mx_printerror("error: file ");
            mx_printerror(comment);
            mx_printerror(" is empty");
            break;
        case INVALID_FIRST_LINE:
            mx_printerror("error: line 1 is not valid");
            break;
        case INVALID_LINE:
            mx_printerror("error: line ");
            mx_printerror(comment);
            mx_printerror(" is not valid");            
            break;
        case INVALID_NUM_ISLANDS:
            mx_printerror("error: invalid number of islands");
            break;
    }
    mx_printerror("\n");
    exit(-1);
}

