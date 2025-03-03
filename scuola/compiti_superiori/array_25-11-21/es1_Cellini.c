#include<stdio.h>

void main ()
{

int l,i,x=0,somma=0;

printf ("\nInserire la lunghezza del vettore:\t");
scanf ("%d",&l);

int arr[l],arr_inverso[l];

for (i=0;i<l;i++)
{
    printf ("\n\nInserire il numero nella cella %d:\t",i);
    scanf ("%d",&arr[i]);
    somma=somma+arr[i];
}

for (i=l-1;i>=0;i--)
{
    arr_inverso[x]=arr[i];
    x++;
}

printf ("\n\nIl vettore inverso e':");

for (i=0;i<l;i++)
{
    printf ("\t%d",arr_inverso[i]);
}

printf ("\n\nLa somma del vettore e':\t%d",somma);


    sleep (5);
    return(0);
}