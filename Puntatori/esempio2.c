#include<stdio.h>

void  main()
{
            //per vedere quanti byte occupano una variabile int, float e char
int a;
char b;
float c;

a = 12;
b = 'F';
c = 6.66666;

printf ("\n\nLa variabile intero occupa %d byte e contiene l'intero %d", sizeof(a), a);              
printf ("\nLa variabile carattere occupa %d byte e contiene il carattere %c", sizeof(b), b);
printf ("\nnLa variabile reale occupa %d byte e contiene il numero %f", sizeof(c), c);

//con sizeof() possiamo vedere la dimensione che occupa la variabile 

    return(0);
}