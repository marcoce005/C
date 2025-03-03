#include<stdio.h>

void main()
{

int i=0;
printf ("\n\nIl primo numero e':\t%d",i++);  //stampa 0 poi incrementa di 1
printf ("\n\nIl secondo numero e':\t%d",i);  //stampa 1
printf ("\n\nIl terzo numero e':\t%d",++i);  //incrementa di 1 e poi stampa 2

sleep (5);
return(0);
}