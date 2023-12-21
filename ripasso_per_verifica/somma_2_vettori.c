#include<stdio.h>

void main()
{

int l, max=0, min;

printf ("\n\nInserire la dimesione degli'array:\t");
scanf ("%d", &l);

int i, arr1[l], arr2[l], somma[l];

printf ("\n\nRiempire il primo array.");
for (i=0;i<l;i++)
{
    printf ("\nInserire il numero nella locazione %d:\t",i);
    scanf ("%d", &arr1[i]);
}

printf ("\n\nRiempire il secondo array.");
for (i=0;i<l;i++)
{
    printf ("\nInserire il numero nella locazione %d:\t",i);
    scanf ("%d", &arr2[i]);
}

printf ("\n\nIl vettore somma e':\t");
for (i=0;i<l;i++)
{
    somma[i] = arr1[i]+arr2[i];
    printf ("%d\t", somma[i]);
}

    sleep (5);
    return(0);
}