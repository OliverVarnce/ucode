#include "libmx.h"

void mx_printerrmes(t_error err, const char *comment) {
    switch (err) {
        case INVLD_NUM_ARGS:
            mx_printerror("usage: ./pathfinder [filename]");
            break;
        case FILE_EXIST:
            mx_printerror("error: file ");
            mx_printerror(comment);
            mx_printerror(" doesn\'t exist");
            break;
        case FILE_EMPTY:
            mx_printerror("error: file ");
            mx_printerror(comment);
            mx_printerror(" is empty");
            break;
        case INVALID_FIRST_LINE:
            mx_printerror("error: line 1 isn\'t valid");
            break;
        case INVALID_LINE:
            mx_printerror("error: line ");
            mx_printerror(comment);
            mx_printerror(" isn't valid");            
            break;
        case INVLD_NUM_ISLDS:
            mx_printerror("error: invalid number of islands");
            break;
    }
    mx_printerror("\n");
    exit(-1);
}