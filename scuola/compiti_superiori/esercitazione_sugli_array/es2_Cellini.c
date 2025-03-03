#include<stdio.h>

void main()
{

int n,l,i,x=0,y=0;

printf ("\nIl programma verifica se i numeri sono pari o dispari e li mette in ordine suddividendo tra pari e dispari.");
printf ("\n\nInserire il numero di celle da creare:\t");
scanf ("%d",&l);

while (l>10)
{
    printf ("\nIl numero massimo di celle e' 10 riprovare.");
    printf ("\n\nInserire il numero di celle da creare:\t");
    scanf ("%d",&l);
}

int arrP[l],arrD[l],contP=0,contD=0;

for (i=0;i<l;i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&n);

    if (n%2==0)
    {
        arrP[y]=n;
        contP++;
        y++;
    }
    else
    {
        arrD[x]=n;
        contD++;
        x++;
    }
}

printf ("\n\nI numeri pari sono:\t");
for (i=0;i<contP;i++)
{
    printf ("%d\t",arrP[i]);   
}

printf ("\nI numeri dispari sono:\t");
for (i=0;i<contD;i++)
{
    printf ("%d\t",arrD[i]);   
}

    sleep (5);
    return(0);
}