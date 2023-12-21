#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {      //funzione che mette in ordine
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int array[] = {2,2,7,34,8,346,59,1,18,136,7,1,4};

    for (int i = 0; i < (sizeof array)/4; i++)
        printf ("%d\t", array[i]);

    qsort (array, (sizeof array)/4, sizeof (int), cmpfunc);   //grazie a questa mette in ordine
    
    printf ("\n");
    
    for (int i = 0; i < (sizeof array)/4; i++)
        printf ("%d\t", array[i]);

    printf ("\n");

    return 0;
}