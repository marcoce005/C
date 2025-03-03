#include<stdio.h>

void ordinavett(int n, char order, int vett[])
{
    int i, x, min;

    for (i=0; i<n-1; i++)
    {
        min=i;
        for (x=i+1; x<n; x++)
        {
            if (vett[x]<vett[min])
            {
                min=x;
            }
        }
        int y=vett[i];
        vett[i]=vett[min];
        vett[min]=y;
    }

    if (order=='C' || order=='c')
    {
        for (int i=0;i<n;i++)
        {
            printf ("%d\t",vett[i]);
        }
    }
    else if (order=='D' || order=='d')
    {
        for (int i=n-1;i>=0;i--)
        {
            printf ("%d\t",vett[i]);
        }
    }
}

void main()
{

int n, i;
char order;

printf ("\n\nInserire la lunghezza del vettore:\t");
scanf ("%d",&n);
int vett[n];

printf ("\n\nRiempire il vettore.\n");
for (i=0; i<n; i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&vett[i]);
}

printf ("\n\nInserire C per oridnare i numeri in ordine cresente o D per ordinare i numeri in ordine decrescente:\t");
scanf ("%s", order);

printf ("\n\nIl vettore in ordine e':\t");
ordinavett(n, order, vett);

printf ("\n\nIl vettore al contrario e':\t");

if (order=='c' || order=='C')
{
    order='d';
}
else if (order=='d' || order=='D')
{
    order='c';
}
ordinavett(n, order, vett);

    
}