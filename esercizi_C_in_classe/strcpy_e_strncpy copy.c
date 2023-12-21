#include<stdio.h>
#include<string.h>

void main()
{

char frase1[]="Tranaso e' un bambino coglione";
char frase2[100];
char frase3[100];

strcpy (frase2,frase1);

printf ("La frase 2 e':\n%s",frase2);

strncpy (frase3,frase1,7);
printf ("\nLa prima parola e':%s",frase3);


    return(0);
}