#include<stdio.h>
#include<string.h>

void main ()
{

char frase[100],frase2[100];

printf ("\nInserire la prima frase:\t");
fgets (frase, sizeof(frase), stdin);
printf ("Inserire la seconda frase:\t");
fgets (frase2, sizeof(frase2), stdin);

strcat (frase,frase2);

printf ("\n\nLa frase completa e':\n");
puts (frase);

    return(0);
}