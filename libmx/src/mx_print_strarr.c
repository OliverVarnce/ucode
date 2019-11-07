#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim){
    if (arr && delim) {
        for(int i = 0; arr[i] != NULL; i++) {
            mx_printstr(arr[i]);
            mx_printstr(delim);

            if (arr[i + 1] == NULL){
                mx_printstr(arr[i]);
                mx_printchar('\n');

            }
        }
    }
}

/*int main() {
    char *arr[] = {"abc","def","ghi", NULL};
    char *delim = "0";
    mx_print_strarr(arr, delim);
    return 0;
}*/
