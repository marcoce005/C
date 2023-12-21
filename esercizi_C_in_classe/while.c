#include <stdio.h>

void main()
{

int n, somma=0,i=0;
float media;

printf ("\nQuesto programma calcola la somma e la media dei numeri fino a quando non si inserisce il valore 00");
printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);

while (n!=00)
{
    somma=somma+n; 
    printf ("\n\nInserire il numero:    ");
    scanf ("%d",&n); 
    i++;
}

media=somma/i;
printf ("\n\nSomma=  %d",somma);
printf ("\n\nMedia=  %f",media);





    sleep (5);
    return(0);
}