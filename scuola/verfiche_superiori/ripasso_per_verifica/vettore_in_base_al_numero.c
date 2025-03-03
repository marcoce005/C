#include<stdio.h>

void main()
{

int l;

printf ("\n\nInserire la lunghezza e il contenuto del vettore:\t");
scanf ("%d",&l);

if (l<=0)
{
    printf ("\n\nVettore inesistente");
}

else
{
    int arr[l], i;
    for (i=0;i<l;i++)
    {
        arr[i]=l;
    }printf ("\n\nIl vettore finale e':");
    
    for (i=0;i<l;i++)
    {
        printf ("\t%d",arr[i]);
    }
}

    sleep (5);
    return(0);
}