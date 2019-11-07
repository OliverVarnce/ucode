#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n){
    size_t i;

    for(i = 0; i < n; i++) {
        if(*((char *)s + i) == c) 
            return (char*)s + i;
    }
            
    return NULL;
}

/*int main (void)
{
   // Исходный массив
   unsigned char src[15]="1234567890";
   // Переменная, в которую будет сохранен указатель
   // на искомый символ.
   char *sym;
   char *symm;

   // Вывод исходного массива
   printf ("src old: %s\n",src);

   // Поиск требуемого символа
   sym = mx_memchr (src, '4', 10);
   symm = memchr (src, '4', 10);

   // Если требуемый символ найден, то заменяем его
   // на символ '!'
   if (sym != NULL)
      sym[0]='!';

   // Вывод исходного массива
   printf ("src new: %s\n",src);

   if (symm != NULL)
      symm[0]='!';

   // Вывод исходного массива
   printf ("src new: %s\n",src);

   return 0;
}*/
