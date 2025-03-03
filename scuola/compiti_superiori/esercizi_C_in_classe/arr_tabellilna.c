#include<stdio.h>

void tabellina (int n)
{
    int i, arr[10], x=0;
    for (i=1;i<11;i++)
    {
        printf ("%d\t",n*i);
    }
}

void main()
{

int n;

printf ("\n\nInserire il numero:\t");
scanf ("%d",& n);
while (n<=0)
{
    printf ("\n\nNumero non valido riprovare\nInserire il numero:\t");
    scanf ("%d",& n);
}

printf ("\n\nLa tabellina e':\t");

tabellina(n);



    return(0);
}