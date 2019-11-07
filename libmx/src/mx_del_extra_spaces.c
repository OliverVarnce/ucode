#include "libmx.h"

int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);

char *mx_del_extra_spaces(const char *str){
    int space = 0;
    int k = 0;
    int n = strlen(str);
    char *tmp = malloc(n + 1 * (sizeof(char)));
    tmp = strcpy(tmp, str);

    for (int i = 0; i < n; i++) {
        while (k == 0 && i < n && tmp[i] == ' ') {
            i++;
        }

        if (tmp[i] == ' ') {
            if (!space) {
                tmp[k++] = str[i];
                space = 1;
            }
        }
        else if (tmp[i] == '.' || tmp[i] == ',' || 
                 tmp[i] == '?') {
            if (k > 0 && tmp[k-1] == ' ') {
                tmp[k-1] = tmp[i];
            }
            else {
                tmp[k++] = tmp[i];
            }
            space = 0;
        }
        else {
            tmp[k++] = tmp[i];
            space = 0;
        }
    }
    tmp[k] = '\0';

    return tmp;
    free(tmp);
}

/*int main(void)
{
    char str[] = "  Hello .   This is   C++    program    !!  ";
    printf("%s\n", mx_del_extra_spaces(str));

    return 0;
}*/
