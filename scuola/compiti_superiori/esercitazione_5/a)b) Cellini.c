#include <stdio.h>

void main()
{

float n_pezzi;

printf ("\nQuesto programma calcola il totale di un numero di pezzi determinati");
printf ("\n\nInserire il numero di prezzi:  ");
scanf ("%f",&n_pezzi);

if (n_pezzi<=0)
{
    printf ("\n\nNumero di pezzi non valido inserire un numero di pezzi positivo");
}

else
{
    if (n_pezzi<30)
    {
        printf ("\n\nIl totale e':  %f", n_pezzi*5);
    }
    
    else if (n_pezzi>=30 && n_pezzi<50)
    {
        printf ("\n\nIl totale e':  %f", (n_pezzi*5)-((n_pezzi*5)/10));
    }

    else 
    {
        printf ("\n\nIl totale e':  %f", (n_pezzi*5)-(((n_pezzi*5)/100)*15));
    }


      
}

    sleep (5);
    return(0);
}