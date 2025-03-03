#include <stdio.h>

void main()
{

int piano,gg;

printf ("\nQuesto programma calcola il il totale in base al piano.");
printf ("\n\nInserire il numero di giorni di soggiorno:    ");
scanf ("%d",&gg);
printf ("\n\nInserire il piano dell'albergo:    ");
scanf ("%d",&piano);


while (piano<=0 || piano >4)
{
    printf ("\n\nPiano dell'albergo non valido riprovare");
    sleep (1);
    printf ("\n\nInserire il piano dell'albergo:    ");
    scanf ("%d",&piano);
}

switch (piano)
{
case 1:
    printf ("\n\nIl totale da pagare e':    %d Euro",gg*35);
break;

case 2:
    printf ("\n\nIl totale da pagare e':    %d Euro",gg*45);
break;

case 3:
    printf ("\n\nIl totale da pagare e':    %d Euro",gg*55);
break;

case 4:
    printf ("\n\nIl totale da pagare e':    %d Euro",gg*65);
break;

default:
break;
}








    sleep (5);
    return(0);
}