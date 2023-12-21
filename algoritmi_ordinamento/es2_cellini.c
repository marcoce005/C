#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

void print(char arr[])
{
    for (int i = 9; i > 0; i--)
        printf ("%c ", arr[i]);
}

int main()
{
    char arr_in[10] = {'g', 'e', 'r', 'y', 'z', 'o', 'p', 'q', 'v', 'd'}, arr_out[10];

    for (int i = 0; i < 10; i++)
        arr_out[i] = arr_in[i];

    qsort (arr_out, 10, sizeof (char), cmpfunc);

    print (arr_out);
    printf ("\n\n");

    return 0;
}