#include<stdio.h>

void main()
{

int i,l;

printf ("\nInserire la lunghezza dell'array:\t");
scanf ("%d",&l);

while (l>10)
{
    printf ("\nValore non valido riprovare.");
    printf ("\nInserire la lunghezza dell'array:\t");
    scanf ("%d",&l);
}


int arr[l];

for (i=0;i<l;i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&arr[i]);
}

printf ("\nI numeri al contrario sono:\t");

for (i=l-1;i>=0;i--)
{
    printf ("%d\t",arr[i]);
}


    sleep (5);
    return(0);
}