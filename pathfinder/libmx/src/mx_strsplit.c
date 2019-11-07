#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }

    int s_arr = mx_count_words(s, c);
    int counter = 0;
    char **result = malloc(sizeof(char *) * (s_arr + 1));
    int len = mx_strlen(s);
    int index = 0;
    if (s_arr == 1) {
        result[0] = mx_strdup(s);
        result[1] = NULL;
        return result;
    }
    for (int i = 0; i < len; i++) {
        index = mx_get_char_index(s, c);
      
        if (index == -1)
            index = mx_strlen(s);
        if (index) {
            result[counter] = mx_strndup(s, index);
            s += mx_strlen(result[counter]) - 1;
            i += mx_strlen(result[counter]) - 1;
            counter++;
        }
        s++;
    } 
    result[s_arr] = NULL;
    return result;
}



/*nt main() {
    int i = 0;
    char *s = "**Good bye,**Mr.*Anderson.****";
    char **arr = mx_strsplit(s, '*');  // arr = ["Good bye,", "Mr.", "Anderson."]
    
    while (arr[i] != NULL) {
        mx_printstr(arr[i]);
        i++;
    }
    
return 0;
}
*/
