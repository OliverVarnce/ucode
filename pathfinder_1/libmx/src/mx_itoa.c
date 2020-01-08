#include "libmx.h"

char *mx_strnew(const int size);

int mx_intsize (long number) {
    int len = 1;

    if (number < 0) {
        number = -number;
        len++;
    }
    while (number / 10) {
        len++;
        number /= 10;
    }

    return len;
}

char* mx_itoa(int number) {
    long nb = number;
    int len = mx_intsize(nb); 
    char *str = mx_strnew(len);
    
    if (nb < 0)
        nb = -nb;
   
    while(len--) {
       str[len] = nb % 10 + 48;
       nb /= 10; 
    }
   
    if (number < 0)
        str[0] = '-';
    return str;

}
