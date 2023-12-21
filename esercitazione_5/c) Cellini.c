#include <stdio.h>

void main()
{

int anno;

printf ("\nQuesto programma verifica se l'anno inserito e'bisestile");
printf ("\n\nInserire l'anno:   ");
scanf ("%4d",&anno);

if (anno%4==0)
{
    printf ("\nL'anno inserito e' bisestile\n\n");
}
else
{
    printf ("\nL'anno inserito non e' bisestile\n\n");
}


    sleep (5);
    return(0);
}