#include<stdio.h>

void main()
{

int mat[4] [4],mat2[4] [4],r,c,mat3[4] [4];

printf ("\n\nInserire i numeri nella prima matrice");
for (r=0;r<4;r++)
{
    for (c=0;c<4;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&mat[r] [c]);
    }
}

printf ("\n\nInserire i numeri nella seconda matrice");
for (r=0;r<4;r++)
{
    for (c=0;c<4;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&mat2[r] [c]);
    }
}

printf ("\n\nIl risulato della somma delle matrici e':\n\n");
for (r=0;r<4;r++)
{
    for (c=0;c<4;c++)
    {
        printf ("%d\t",mat[r] [c] + mat2[r] [c]);
    }
    printf ("\n");
}


    sleep (5);
    return(0);
}