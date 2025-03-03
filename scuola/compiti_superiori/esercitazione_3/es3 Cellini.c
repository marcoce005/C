#include <stdio.h>


void main()
{

float b,h,Area;


printf ("\n\nIl programma calcola l'Area di un rettangolo con base e altezza determinate");
printf ("\n\nInserire il valore della base\n ");
scanf ("%f", &b);
printf ("\n\nInserire il valore dell'altezza'\n ");
scanf ("%f", &h);

Area = b*h;


printf ("\n\nArea=%f", Area);
printf (" cm");
printf ("\n\n");


sleep (5000);


}