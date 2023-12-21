#include<stdio.h>

void main()
{

int n,i=0,somma=0;

while (somma<=50)
{

    if  (i>=100)
    {
        break;
    }

    printf ("\nInserire il numero:\t");
    scanf ("%d",&n);

    if (n!=0)
    {
        somma=somma+n;
        i++;
    }
    else
    {
        i++;
    }
}

printf ("\n\nLa somma dei numeri inseriti e':\t%d",somma);

    sleep (5);
    return(0);
}