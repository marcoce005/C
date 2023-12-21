#include<stdio.h>

void main()
{

int l;

printf ("\n\nInserire la dimesione dell'array:\t");
scanf ("%d", &l);

int i, arr[l];

printf ("\n\nRiempire l'array. ");
for (i=0;i<l;i++)
{
    printf ("\nInserire il numero nella locazione %d:\t",i);
    scanf ("%d", &arr[i]);
}

printf ("\n\nArray iniziale =\t");
for (i=0;i<l;i++)
{
    printf ("%d\t",arr[i]);
}

printf ("\n\nArray contrario =\t");
for (i=l-1;i>=0;i--)
{
    printf ("%d\t",arr[i]);
}
    sleep (5);
    return(0);
}