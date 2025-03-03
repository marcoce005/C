#include<stdio.h>

void main()
{

int mat[2] [2],r,c,n;

printf ("\n\nInserire nella matrice solo numeri pari.\n");

for (r=0;r<2;r++)
{
    for (c=0;c<2;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&n);

        if (n%2==0)
        {
            mat[r] [c]=n;
        }
        else
        {
            c--;
        }
    }
}

printf ("\n\nLa matrice inserita e':\n\n");
for (r=0;r<2;r++)
{
    for (c=0;c<2;c++)
    {
        printf ("%d\t",mat[r] [c]);
    }
    printf ("\n");
}

    sleep (5);
    return(0);
}