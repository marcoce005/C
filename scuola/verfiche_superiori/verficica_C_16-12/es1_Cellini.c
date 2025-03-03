#include<stdio.h>

void main()
{

int n,i;

printf ("\n\nInserire la lunghezza del vettore:\t");
scanf ("%d",&n);

while (n%2!=0)
{
    printf ("\n\nLunghezza non valida in serire una lunghezza pari.");
    printf ("\n\nInserire la lunghezza del vettore:\t");
    scanf ("%d",&n);
}

char vet[n];

printf ("\n\nRiempire il vettore\n");
for (i=0;i<n;i++)
{
    printf ("\nInserire il carattere:\t");
    scanf ("%s",& vet[i]);
}

printf ("\n\nIl vettore iniziale e':\t");
for (i=0;i<n;i++)
{
    printf ("%c\t",vet[i]);
}

n=n/2;

printf ("\n\nIl vettore finale e':\t");
for (i=n;i<n*2;i++)
{
    printf ("%c\t",vet[i]);
}

for (i=0;i<n;i++)
{
    printf ("%c\t",vet[i]);
}


    sleep (5);
    return(0);
}