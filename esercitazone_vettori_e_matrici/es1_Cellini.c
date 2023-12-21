#include<stdio.h>

void main()
{

int b,h,r,c;

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
    }
}

printf ("\n\nLa matrice inserita e':\n\n");
for (r=0;r<h;r++)
{
    for (c=0;c<b;c++)
    {
        printf ("%d\t",mat[r] [c]);
    }
    printf ("\n");
}


    sleep (5);
    return(0);
}