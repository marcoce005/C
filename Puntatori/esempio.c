#include <stdio.h>

void main()
{

int *pa, a = 10;      // pa è una variabile di tipo puntatore all'intero int 
pa = &a;        //stampa l'indirizzo di a

printf ("\n\nIndirizzo della variabile e':\t%p",pa);    //Si usa %p per stampare l'indirizzo
printf ("\nValore Variabile e':\t%d", *pa);    //Oppure potrei mettere printf ("\nValore Variabile e':\t%d", a);

















    return(0);
}