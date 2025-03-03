#include <stdio.h>


void main()
{

float l;
float Perimetro;
float Area;

printf ("\n\nIl programma calcola il Perimetro e l'Area di un quadrato con un determinato lato");
printf ("\n\nInserire il lato del quadrato\n ");
scanf ("%f", &l);

Perimetro = l*4; 
Area = l*l;

printf ("\n\nPerimetro=%f", Perimetro); 
printf (" cm");
printf ("\n\nArea=%f", Area);
printf (" cm");
printf ("\n\n");

sleep (5000);


}