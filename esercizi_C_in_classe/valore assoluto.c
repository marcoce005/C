#include <stdio.h>

void main()
{

int n;

printf ("\nIl programma da il valore assoluto di un numero.");
printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);

if (n<0)
{
    printf ("\n\nIl numero in valore assoluto e' |%d| ovvero %d",n,n*-1);
}

else
{
    printf ("\n\nIl numero in valore assoluto e' |%d| ovvero %d",n,n);
}
    sleep (5);
    return(0);
}
