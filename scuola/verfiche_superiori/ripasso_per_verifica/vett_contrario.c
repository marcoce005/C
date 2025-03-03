#include<stdio.h>

void main()
{

int arr[10], i;

printf ("\n\nRiempire il vettore.\n");
for (i=0;i<10;i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&arr[i]);
}

printf ("\n\nIl vettore originale e':\t");
for (i=0;i<10;i++)
{
    printf ("%d\t",arr[i]);;
}

printf ("\n\nIl vettore al contrario e':\t");
for (i=9;i>=0;i--)
{
    printf ("%d\t",arr[i]);
}



    return(0);
}