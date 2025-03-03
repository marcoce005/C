#include<stdio.h>

void main()
{

int l, max=0, min;

printf ("\n\nInserire la dimesione dell'array:\t");
scanf ("%d", &l);

int i, arr[l];

printf ("\n\nRiempire l'array. ");
for (i=0;i<l;i++)
{
    printf ("\nInserire il numero nella locazione %d:\t",i);
    scanf ("%d", &arr[i]);
    if (arr[i]>=max)
    {
        max=arr[i];
    }
    if (i==0)
    {
        min=arr[i];
        max=arr[i];
    }
    else if (arr[i]<=min)
    {
        min=arr[i];
    }
}

printf ("\n\nIl numero massimo e':\t%d",max);
printf ("\n\nIl numero minimo e':\t%d",min);

    sleep (5);
    return(0);
}