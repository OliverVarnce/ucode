#include "libmx.h"

int mx_quicksort(char **arr, int left, int right){
    int i, j, p;

    if(left < right){
        p = left;
        i = left;
        j = right;

        while(i < j){
            while(arr[i] <= arr[p] && i < right)
                i++;
            while(arr[j] > arr[p])
                j--;
            if(i < j){
                mx_swap_char(arr[i], arr[j]);
            }
        }
        mx_swap_char(arr[p], arr[j]);
      
        mx_quicksort(arr,left,j-1);
        mx_quicksort(arr,j+1,right);
   }
   return **arr; 
}


/*int main() 
{ 
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    printf("%d", mx_quicksort(arr, 0, 3)); 
 
    return 0; 
} */
