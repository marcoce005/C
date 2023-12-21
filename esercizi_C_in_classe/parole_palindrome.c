#include<stdio.h>
#include<string.h>

void main()
{

char parola[100];
int l;

printf ("\nInserire la poarola da verificare se e' palindroma:\t");
scanf ("%s",&parola);

l=(strlen (parola))/2;

char pez1[l];
char pez2[l];

strncpy (pez1,parola,l);
printf ("%s",pez1);

printf ("\n%c",parola[3]);

    return(0);
}