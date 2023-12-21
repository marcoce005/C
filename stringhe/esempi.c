#include<stdio.h>
#include<string.h>

void main()
{

char frase[20];

printf ("\n\nInseire la stringa:\t");
fgets  (parola, sizeof(parola), stdin);             // acquisire una frase con spazi
puts(parola);           // stampare la stringa

}