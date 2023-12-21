#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void print(float arr[])
{
    for (int i = 0; i < 10; i++)
        printf ("%f  ", arr[i]);
}

int main()
{
    float arr_in[10] = {0.1, 1.11, 4.25, 6.2, 10, 6.2, 3.8, 7.3, 0.42, 0.000001}, arr_out[10];

    qsort (arr_in, 10, sizeof (float), cmpfunc);

    for (int i = 0; i < 10; i++)
        arr_out[i] = arr_in[i];

    print (arr_out);
    printf ("\n\n");

    return 0;
}