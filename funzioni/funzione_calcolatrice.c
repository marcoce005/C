#include<stdio.h>

float calcolasom(float a, float b)
{
    float som = a + b;
    return(som);
} 

float calcoladif(float a, float b)
{
    float dif = a - b;
    return(dif);
}

float calcolamul(float a, float b)
{
    float mul = a * b;
    return(mul);
}

float calcoladiv(float a, float b)
{
    float div = a / b;
    return(div);
}

void main()
{

float x, y, somma, divisione, moltiplicazione, differenza;
char simbolo;

printf ("\n\nInserire il primo numero:\t");
scanf ("%f",&x);

printf ("\n\nInserire l'operatore :\t");
scanf ("%s",&simbolo);

printf ("\nInserire il secondo numero:\t");
scanf ("%f",&y);

somma = calcolasom (x, y);
differenza = calcoladif (x, y);
moltiplicazione = calcolamul (x, y);
divisione = calcoladiv (x, y);

printf ("\n\nIl risultato e':\n");
switch (simbolo)
{
case '+':
            printf ("\t%f + %f = %f",x , y, somma);
    break;

case '-':
            printf ("\t%f - %f = %f",x , y, differenza);
    break;

case '*':
            printf ("\t%f * %f = %f",x , y, moltiplicazione);
    break;

case '/':
            printf ("\t%f / %f = %f",x , y, divisione);
    break;

default:
    break;
}


    return(0);    
}