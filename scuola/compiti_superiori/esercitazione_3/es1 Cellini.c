#include <stdio.h>

void main()

{

float n1;
float n2;
float somma;
float media;

printf ("\n\n");
printf ("Il programma calcola la somma e la media di due numeri");
printf ("\n\nInserire il primo numero:\n");
scanf ("%f",&n1);
printf ("\n");
printf ("Inserisci il secondo valore:\n");
scanf ("%f",&n2);

somma = n1+n2;
media = somma/2;

printf ("\n\n");
printf ("Somma= %f" , somma);
printf ("\n\n");
printf ("Media= %f" , media);
printf ("\n\n");


sleep (5000);



}




