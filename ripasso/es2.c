#include<stdio.h>

void max(int vet[])
{
    int max=vet[0], k;
    for (int i=0; i<8; i++)
    {
        if (vet[i]>=max)
        {
            max=vet[i];
            k=i;
        }
    }
    printf ("\n\nIl numero massimo e':\t%d si trova nella locazione %d", max, k);
}

void min(int vet[8])
{
    int min=vet[0], k;
    for (int i=0; i<8; i++)
    {
        if (vet[i]<=min)
        {
            min=vet[i];
            k=i;
        }
    }
    printf ("\n\nIl numero massimo e':\t%d si trova nella locazione %d", min, k);
}

void main()
{

int vet[8];

printf ("\n\nRiempire l'array");
for (int i=0; i<8; i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d", &vet[i]);
}

max(vet);
min(vet);

}