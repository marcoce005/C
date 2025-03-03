#include <stdio.h>

void main()
{

float n1,n2;
char simbolo;

printf ("\nQuesto programma e' una calcolatrice");
printf ("\n\nInserire il primo valore:  ");
scanf ("%f",&n1);
printf ("\n\nQuale operatore si vuole eseguire:  ");
scanf (" %c",&simbolo);
printf ("\n\nInserire il secondo valore:    ");
scanf ("%f",&n2);


switch (simbolo)
{
case '+':
    printf ("\n\nLa somma e':   %f",n1+n2);
break;

case '-':
    printf ("\n\nLa differenza e':   %f",n1-n2);
break;

case '*':
    printf ("\n\nLa prodotto e':   %f",n1*n2);
break;

case '/':
    printf ("\n\nLa somma e':   %f",n1/n2);
break;

default:
    printf ("\n\nOperatore  non valido riprovare");
break;
}














sleep (5);
return(0);
}