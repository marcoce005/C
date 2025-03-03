#include<stdio.h>

void main()
{

int n,i,fatt=1,somma=0;

printf ("\nQuesto programma calcola il fattoriale e la somma di un numero");
printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);

for (i=1;i<=n;i++)
{
    fatt=fatt*i;
    somma=somma+i;
}

printf ("\n\nIl fattoriale del numero %d e': %d",n,fatt);
printf ("\n\nLa somma dei numeri precedenti al numero %d e': %d",n,somma);





    sleep (5);
    return (0);
}