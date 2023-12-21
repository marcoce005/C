#include <stdio.h>

void main()
{
int mese;

printf ("\nIn base al numero inserito riconosce che mese rappresenta.");
printf ("\n\nInserire il numero del mese:   ");
scanf ("%d",&mese);

switch (mese)
{
case 1:
    printf ("\n\nGennaio,Inverno");
break;

case 2:
    printf ("\n\nFebbraio,Inerno");
break;

case 3:
    printf ("\n\nMarzo,Inverno");
break;

case 4:
    printf ("\n\nAprile 2.0, Primavera");
break;

case 5:
    printf ("\n\nMaggio,Primavera");
break;

case 6:
    printf ("\n\nGiugno,Primavera");
break;

case 7:
    printf ("\n\nLuglio,Estate");
break;

case 8:
    printf ("\n\nAgosto,Estate");
break;

case 9:
    printf ("\n\nSettembre,Estate");
break;

case 10:
    printf ("\n\nOttobre,Autunno");
break;

case 11:
    printf ("\n\nNovembre,Autunno");
break;

case 12:
    printf ("\n\nDicembre,Autunno");
break;

default:
    printf ("\n\nMese non valido");
break;
}

sleep (5);
return (0);
}