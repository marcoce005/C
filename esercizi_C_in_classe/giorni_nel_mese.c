#include <stdio.h>
#include <string.h>

void main()
{
int mese;

printf ("\nQuesto programma calcola quanti giorni ha un detrerminato mese.");
printf ("\n\nInserire il numero del mese:   ");
scanf ("%2d",&mese);

while (mese<13 || mese<=0)
{
    printf ("\n\nNumero del mese sbagliato riprovare");
    sleep (1);
    printf ("\n\nInserire il numero del mese:   ");
    scanf ("%1d",&mese);
}

switch (mese)
{
case 2:
    printf ("\n\nIl mese ha 28 o 29 giorni in base all'anno");
break;

case 1 || 3 || 5 || 7 || 8 || 10 || 12:
    printf ("\n\nQuesto mese a 31 giorni");
break;

case 4 || 6 || 9 || 11:
    printf ("\n\nQuesto mese a 30 giorni");
break;

default:
    break;
}




















    return(0);
}