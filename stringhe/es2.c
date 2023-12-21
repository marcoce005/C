#include<stdio.h>
#include<string.h>

void stampa(char frase[])
{
    puts(frase);
}

void main()
{

char frase[20];

printf ("\n\nInserire la frase:\t");
fgets (frase, sizeof(frase), stdin);

printf ("\n\nLa frase e':\t"); 
stampa(frase);

printf ("%c", *(frase+5));          // stampa la locazione 1+5 ovvero sei

}