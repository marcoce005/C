#include <stdio.h>

void main()
{

int n, somma_p=0, somma_d=0;

printf ("\nQuesto programma calcola la somma dei numeri pari e di quelli dispari fino a quando non si inserisce 00");
printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);

while (n!=0)
{
    if (n%2==0)
    {
        somma_p=somma_p+n;
    }

    else
    {
        somma_d=somma_d+n;
    }
    
    printf ("\n\nInserire il numero:    ");
    scanf ("%d",&n);
}

printf ("\n\nLa somma dei numeri pari e':   %d",somma_p);
printf ("\n\nLa somma dei numeri dispari e':   %d",somma_d);


    sleep (5);
    return(0);
}