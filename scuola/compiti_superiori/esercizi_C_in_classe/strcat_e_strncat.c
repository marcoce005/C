#include<stdio.h>
#include<string.h>

void main()
{

char frase1[100]="Tranaso e' un bambino coglione ";
char frase2[]=" mentre Scattaglia gioca a bralw starts";
char frase3[100];
char frase4[]=" quel pezzo di merda";

strcat (frase1,frase2);
strcpy (frase3,frase1);


printf ("\nLa frase completa e':\n%s\n\n",frase3);

strncat (frase3,frase4,11);

printf ("\nLa frase completa e':\n%s\n\n",frase3);


    return(0);
}