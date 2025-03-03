#include<stdio.h>

void main()
{

int l,r;

printf ("\n\nInserire la lunghezza del vettore:\t");
scanf ("%d",&l);

int vet[l],i,cont=0;

printf ("\n\nRiempire il vettore creato in precedenza\n");
for (i=0;i<l;i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&vet[i]);
}

for (i=0;i<l-1;i++)
{
    if (vet[i]==0 && vet[i+1]==1 || vet[i]==1 && vet[i+1]==0)
       {}
    else
    {
        cont++;
    }   
}


if (cont>0)
{
    printf ("\n\nIl vettore inserito non e' una scacchiera perche' ci sono altri valori rispetto 0 e 1");
}
else
{
    printf ("\n\nIl vettore inserito e' una scacchiera perche' ci sono solo 0 e 1");
}

printf ("\n\nIl vettore inserito e' questo:\n\n");
for (i=0;i<l;i++)
{
    printf ("%d\t",vet[i]);
}

    sleep (5);
    return(0);
}