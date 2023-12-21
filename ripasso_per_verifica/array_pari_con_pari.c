#include<stdio.h>

void main()
{

int l;

printf ("\n\nInserire la dimesione dell'array:\t");
scanf ("%d", &l);

int i, arr[l];

printf ("\n\nRiempire l'array. ");
for (i=1;i<=l;i++)
{
    printf ("\nInserire il numero nella locazione %d:\t",i);
    scanf ("%d", &arr[i]);

    if(i%2==0 && arr[i]%2==0)
    {
        printf ("\nOk e' giusto tutto pari.");
    }
    else if (i%2==1 && arr[i]%2==1)
    {
        printf ("\nOk e' giusto tutto dispari.");
    }
    else
    {
        printf ("\nNon giusto.");
    }
}


    sleep (5);
    return(0);
}