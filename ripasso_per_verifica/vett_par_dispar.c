#include<stdio.h>

void main()
{
int l;

printf ("\n\nInserire la lunghezza del vettore\t");
scanf ("%d",&l);

int arr[l], i, y=0, x=0, contp=0, contd=0;

printf ("\n\nRiempire l'array.\n");
for (i=0;i<l;i++)
{
    i==0 || i%2==0 ? contp++ : contd++;
    printf ("\nInserire numero:\t");
    scanf ("%d",&arr[i]);
}

int arrp[contp], arrd[contd];

for (i=0;i<l;i++)
{
    if (i==0 || i%2==0)
    {
        arrp[x++]=arr[i];
    }
    else
    {
        arrd[y++]=arr[i];
    }
}

printf ("\n\nI numeri nelle locazioni pari sono:\t");
for (i=0;i<contp;i++)
{
    printf ("%d\t",arrp[i]);
}

printf ("\n\nI numeri nelle locazioni dispari sono:\t");
for (i=0;i<contd;i++)
{
    printf ("%d\t",arrd[i]);
}

    return(0);
}