#include<stdio.h>

void main()
{

int n;

printf ("\nQuesto programma permetta di analizzare se un numero e' positivo o negativo e pari o dispari.");

printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);

while (n!=00)       //Fino a quando il numero e' diverso da 00 o 0 inserisco dei numeri.
{
    if (n>0)        //Controllo se e' positivo.
    {
        printf ("\nIl numero e' positivo");

        if (n%2==0)         //Controllo se e' pari.
        {
            printf (" e pari");
        }

        else                //Altrimenti e' dispari.
        {
            printf (" e dispari");
        }
    }
    else        //Altrimenti e' negativo.
    {
        printf ("\nIl numero e' negativo");

        if (n%2==0)         //Controllo se e' pari.
        {
            printf (" e pari");
        }

        else                //Altrimenti e' dispari.
        {
            printf (" e dispari");
        }
    }

printf ("\n\nInserire il numero:    ");
scanf ("%d",&n); 

}






    sleep (5);
    return(0);
}