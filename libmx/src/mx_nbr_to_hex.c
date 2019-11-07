#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){
	long tmp;
 	int i = 0, j = 0, size;
 	char *r, hex[100];


 	
 	while (nbr != 0)
 	{
 		tmp = nbr % 16;
 		if(tmp < 10) {
 			hex[i++] = tmp + 48;
 		}
 		else {
 			hex[i++] = tmp + 87;
 		}
 		
 		nbr /= 16;
 	}
 	size = i;
 	i--;
 	r = mx_strnew(tmp);

 	for (j = 0; j <= size; j++, i--)
 		r[j] = hex[i];
 	return r;
}
