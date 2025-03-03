#include<stdio.h>

void main()
{

printf ("\n\nIl programma verifica quante volte e' stato inserito il numero 1");

int i,l,cont=0;

printf ("\n\nInserire il numero di celle da creare:\t");
scanf ("%d",&l);

int arr[l];

for (i=0;i<l;i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&arr[i]);

    if (arr[i]==1)
    {
        cont++;
    }
}

if (cont<=1)
{
    printf ("\n\nI numero 1 e' stato inserito %d volta",cont);
}
else
{
    printf ("\n\nI numero 1 e' stato inserito %d volte",cont);
}

    return(0);
}