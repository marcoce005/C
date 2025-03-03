#include <stdio.h>

void main()
{
float n,n2,somma,media;



printf ("\n\nQuesto programma calcola la somma, la media e qual e' maggiore tra due numeri\n");
printf ("\n\nInserire il primo numero:");
scanf ("%f",&n);
printf ("\n\nInserire il secondo numero:");
scanf ("%f",&n2);

somma=n+n2;
media=somma/2;


printf ("\n\nLa somma e': %f",somma);
printf ("\n\nLa media e': %f",media);

if (n>=5 && n<=10)
{
    printf ("\n\nIl primo numero e' compreso tra 5 e 10");
}
else 
{
    printf ("\n\nIl primo numero non e' compreso tra 5 e 10");
}

if (n2>=5 && n2<=10)
{
    printf ("\n\nIl secondo numero e' compreso tra 5 e 10\n\n");
}
else 
{
    printf ("\n\nIl secondo numero non e' compreso tra 5 e 10\n\n");
}


return(0);
sleep (5000);

}