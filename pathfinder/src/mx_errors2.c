#include "pathfinder.h"

void mx_invalid_num_of_islds() {
    mx_printerr("error: invalid number of islands\n");
    exit(0);
}

void mx_apex_count(char **islArr) {
    if (!str_is_digit(islArr[0])) {
        mx_printerr("error: line 1 is not valid\n");
        exit (0);
    }
}


void mx_print_erno(char *num) {
    mx_printerr(LINE_VALUE_START);
    mx_printerr(num);
    mx_printerr(LINE_VALUE_END);
}

