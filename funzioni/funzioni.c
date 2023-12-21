#include<stdio.h>

float calcolamedia(float x, float y)  //creamo la funzione che calcola la media
{
    float media = (x + y)/2;
    
    return(media);
}

float calcolamax(float x, float y)
{
    float max;
    if (x>y)
    {
        max=x;
    }
    else
    {
        max=y;
    }
    return(max);    
}

void main()
{

float a=20, b=10, risultato, massimo;

risultato = calcolamedia (a, b);
massimo = calcolamax (a, b);

printf ("\n\nValore media = %f",risultato);

printf ("\n\nValore massimo = %f",massimo);















    return(0);
}