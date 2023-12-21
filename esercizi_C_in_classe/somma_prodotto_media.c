#include<stdio.h>

void main()
{

float n,somma=0,prod=1;
int i;

for (i=1;i<=4;i++)
{
    printf ("\n\nInserisci il %d^ numero:   ",i);
    scanf ("%f",&n);

    somma=somma+n;
    prod=prod*n;
}

printf ("\n\nLa somma, il prodotto e la media del numero %f sono:    %f e %f e %f",n,somma,prod,somma/4);






}