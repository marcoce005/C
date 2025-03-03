#include <stdio.h>

void main()
{

int i,n;

printf ("\nQuesto programma calcola la tabellina di un numero");
printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);
printf ("\n\nLa tabellina del numero %d e': ",n);

for (i=1;i<=10;i++)
{
    printf (" %d ",n*i);
}


    sleep (5);
    return(0);
}