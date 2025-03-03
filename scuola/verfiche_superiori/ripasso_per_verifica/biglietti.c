#include<stdio.h>

void main()
{

char arr[7];

printf ("\n\nInserire il codice del biglietto:\t");
scanf ("%s",arr);

int l=strlen(arr);

arr[0]=='T' && l==7 ? printf ("\n\nBiglietto valido.") : printf ("\n\nBiglietto non valido.");


    return(0);
}