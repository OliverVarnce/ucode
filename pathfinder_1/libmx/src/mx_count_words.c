#include "libmx.h"


int mx_count_words(const char *str, char c){

    int k = 0, i = 0, cnt = 0;

    if (str == NULL || !c) 
        return -1;
    
    while (str[i]) {
        if (str[i] == c && k == 0){
            i++;   
        }
        else if (str[i] != c && k == 0) {
            k++;
            cnt++;
            i++;
        }
        else if (str[i] == c && k != 0) {
            k = 0;
            i++;
        }
        else if (str[i] != c && k != 0) {
            i++;
        }
    }
    return cnt;
}


/*int main(){
    char *str = "  follow  *   the  white rabbit ";
    printf("%d\n\n", mx_count_words(str, '*'));
    printf("%d\n\n", mx_count_words(str, ' '));
    printf("%d\n\n", mx_count_words(NULL, ' '));
    return 0;
}*/
