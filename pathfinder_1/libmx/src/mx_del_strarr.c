#include "libmx.h"

void mx_del_strarr(char ***arr) {
    int i = 0;
    char **array = *arr;
    while (array[i] != NULL) {
        mx_strdel(&array[i]);
        i++;
    }
    free(arr);
    *arr = NULL;
}

/*int main() {
    char **arr = malloc(13 * sizeof(char));

    arr[0] = malloc(9 * sizeof(char));
    arr[1] = malloc(9 * sizeof(char));
    arr[0] = mx_strcpy(arr[0], "wakafloka");
    arr[1] = mx_strcpy(arr[1], "hello");
    arr[2] = NULL;
    
    for (int i = 0; arr[i] != NULL; i++) {
        printf("%s\n", arr[i]);
    }
    
    mx_del_strarr(&arr);
  
   
    for (int i = 0; arr[i] != NULL; i++) {
        printf("%s\n", arr[i]);
    }
   
    return 0;
}*/
