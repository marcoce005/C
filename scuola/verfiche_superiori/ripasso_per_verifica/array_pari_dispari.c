#include<stdio.h>

void main()
{

int l;

printf ("\n\nInserire la dimesione dell'array:\t");
scanf ("%d", &l);

int i, arr[l], arrp[l], arrd[l], contp=0, contd=0;

printf ("\n\nRiempire l'array. ");
for (i=0;i<l;i++)
{
    printf ("\nInserire il numero nella locazione %d:\t",i);
    scanf ("%d", &arr[i]);
    
    if (arr[i]%2==0)
    {
        arrp[contp]=arr[i];
        contp++;
    }
    else
    {
        arrd[contd]=arr[i];
        contd++;
    }
}

printf ("\n\nI numeri pari sono:\t");
for (i=0;i<contp;i++)
{
    printf ("%d\t",arrp[i]);
}

printf ("\n\nI numeri dispari sono:\t");
for (i=0;i<contd;i++)
{
    printf ("%d\t",arrd[i]);
}

    sleep (5);
    return(0);
}