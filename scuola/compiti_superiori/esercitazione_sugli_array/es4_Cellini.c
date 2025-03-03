#include<stdio.h>

void main()
{

int mat[5] [5],i,n,m,r,c,cont=0;

printf ("\n\nQuesto programma verifica se  i numeri contenuti nella matrice sono compresi tra due determinati numeri.");
printf ("\n\nInserire l'inzio del gap:\t");
scanf ("%d",&n);
printf ("\n\nInserire la fine del gap:\t");
scanf ("%d",&m);

while (n==m)
{
    printf ("\n\nNumeri non validi (non esiste un gap) riprovare");
    printf ("\n\nInserire l'inzio del gap:\t");
    scanf ("%d",&n);
    printf ("\n\nInserire la fine del gap:\t");
    scanf ("%d",&m);
}

for (r=0;r<5;r++)
{
    for (c=0;c<5;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&mat[r] [c]);
    }
}

for (r=0;r<5;r++)
{
    for (c=0;c<5;c++)
    {
        if ((mat[r] [c]<=m && mat[r] [c]>=n) || (mat[r] [c]<=n && mat[r] [c]>=m))
        {}
        else
        {
            printf ("\nIl numero nella locazione della matrice [righa %d colonna %d] non e' compreso nel gap prestabilito.",r,c);
            cont++;
        }
    }
}

if (cont==0)
{
    printf ("\n\nTutti i numeri sono compresi nel gap tra %d e %d",n,m);
}



    sleep (5);
    return(0);
}