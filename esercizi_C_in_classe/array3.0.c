#include<stdio.h>
#include<string.h>

void main()
{

char frase[] = "Tranaso e' un fottuto bambino del c***o e Scattaglia e suo fidato scudiero che gioca a brawl star o dorme.";
int i=0;

printf ("\n\n");

while (frase[i]!='\0')
{
    printf ("%c",frase[i]);
    i++;
}

printf ("\n\n");

    sleep (5);
    return(0);
}