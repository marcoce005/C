#include<stdio.h>
#include<string.h>

void main ()
{

char frase[50];

printf ("\nInserire la prima frase:\t");
fgets (frase, sizeof(frase), stdin);

if (islower(frase)==0)
{
    printf ("\n\nmaiuscolo");

    printf ("\n\n%s",tolower(frase));

}
else 
{
    printf ("\n\nminuscolo");
    tolower (frase);
    printf ("\n\n%s",frase);
}



    return(0);
}