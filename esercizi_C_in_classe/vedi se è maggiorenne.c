#include <stdio.h>

void main()
{
int anno;

printf ("\nQuesto programma verifica se sei maggiorenne.");
printf ("\n\nInserire l'anno di nascita:    ");
scanf ("%4d",&anno);

if (anno<1900)
{
    printf ("\n\nOhhhhhh, che sei un Vampiro!!!!!!!!!");
}
else if ((2021-anno)<18)
{
    printf ("\n\nSei minorenne");
}
else
{
    printf ("\n\nSei maggiorenne");
}
    sleep (5);
    return(0);
}