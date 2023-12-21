#include <stdio.h>
#include <math.h>

void main()
{

int c1,i,P;
float c2,A;

printf ("\nQuesto algoritmo calcola un cateto, l'area e il perimetro dato un'altro cateto e l'ipotenusa");
printf ("\n\nInserire il valore dell'ipotenusa: ");
scanf ("%d",&i);
printf ("\n\nInserire il valore del cateto: ");
scanf ("%d",&c1);

c2=sqrt((i*i)-(c1*c1));
P=c1+c2+i;
A=(c1*c2)/2;

printf ("\n\nIl valore del secondo cateto e': %f",c2);
printf ("\n\nIl valore del perimetro e': %d",P);
printf ("\n\nIl valore dell'area e': %f",A);

sleep (5);
return(0);

}