#include<stdio.h>

void main()
{

int b,h,r,c,cont=0;

printf ("\n\nInserire la base della matrice da creare:\t");
scanf ("%d",&b);
printf ("\nInserire l'altezza della matrice da creare:\t");
scanf ("%d",&h);

int mat[b] [h];

printf ("\n\nInserire i valori dentro la matrice");
for (r=0;r<h;r++)
{
    for (c=0;c<b;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&mat[r] [c]);

        if (mat[r] [c]==0)
        {
            cont++;
        }
    }
}

printf ("\n\nIl numero di zeri inseriti nella matrice sono:\t%d",cont);

    sleep (5);
    return(0);
}