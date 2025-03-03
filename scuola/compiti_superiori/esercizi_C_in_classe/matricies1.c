#include<stdio.h>

void main()
{

int b,r,c;

printf ("\n\nInserire la dimensione della matrice per avere il numero 1 sulle diagonali.");
printf ("\n\nLa base e':\t");
scanf ("%d",&b);
printf ("\n\n");

for (r=0;r<b;r++)
{
    for (c=0;c<b;c++)
    {
        if (r+c==b-1 || r==c)
        {
            printf ("1\t");
        }
        else
        {
            printf ("0\t");
        }
    }
    printf ("\n");
}











    return(0);
}