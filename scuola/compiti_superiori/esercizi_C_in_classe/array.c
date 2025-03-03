#include<stdio.h>

void main()
{

int l,i,somma=0;

printf ("\n\nInserire il numero di celle:   ");
scanf ("%d",&l);

int a [l];

for (i=0;i<l;i++)
{
    printf ("\nInserire il numero nella locazione %d:   ",i);
    scanf ("%d",&a [i]);
    somma=somma+a [i];
}

printf ("\nLa somma e': %d\n\n",somma);


    sleep (5);
    return(0);
}