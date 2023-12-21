#include<stdio.h>
#define lunghezza 4
void main()
{

int arr[lunghezza],i,somma=0;

printf ("\nInserire un vettore di %d numeri",lunghezza);

for (i=0;i<lunghezza;i++)
{
    printf ("\n\nInserire il numero nel vettore:\t");
    scanf ("%d",&arr[i]);
    somma=somma+arr[i];
}

printf ("\n\nLa somma e':\t%d",somma);

    return(0);
}