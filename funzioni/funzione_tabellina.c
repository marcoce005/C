#include<stdio.h>

void calcolatabellina(int n)
{
    int i;
    for (i=1;i<11;i++)
    {
        printf ("\t%d",n*i);
    }
}

void main()
{

int n;

printf ("\n\nInserire il numero:\t");
scanf ("%d",& n);

printf ("\n\nLa tabellina e':");

calcolatabellina(n);

    return(0);
}