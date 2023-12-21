#include<stdio.h>

void main ()
{

int l,i;

printf ("\n\nInserire il numero di celle da creare: ");
scanf ("%d",&l);

int a [l];

for (i=0;i<l;i++)
{
    printf ("\nInserire il valore nella cella %d:  ",i);
    scanf ("%d",&a [i]);
}

printf ("\n\nI numeri in contrario sono:    ");

for (i=i-1;i>=0;i--)
{
    printf ("%d ",a [i]);
}


    return(0);
}