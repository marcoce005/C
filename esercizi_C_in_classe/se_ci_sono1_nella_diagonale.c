#include<stdio.h>

void main()
{

int r,c,b,h;

printf ("\n\nInserire le dimensioni della matrice");
printf ("\n\nLe righe sono:\t");
scanf ("%d",&b);
printf ("\n\nLe colonne sono:\t");
scanf ("%d",&h);

if (r==c)
{
    int mat [r][c],vet[r],x=0,cont=0;

    printf ("\n\nRiempire la matrice\n");
    for (r=0;r<b;r++)
    {
        for (c=0;c<h;c++)
        {
            printf ("\nInserire il numero:\t");
            scanf ("%d",&mat[r][c]);
        }
    }

    for (r=0;r<b;r++)
    {
        for (c=0;c<h;c++)
        {
            if (r==c)
            {
                vet[x++]=mat[r][c];
            }
            else
            {
                cont++;
            }
        }
    }
    if (cont==0)
    {
        printf ("\n\nLa diagonale e' composta tutta da stessi numeri");
    }
}
else
{
    printf ("\n\nLa matrice non e' quadrata");
}

for (r=0;r<b;r++)
{
        for (c=0;c<h;c++)
    {
        printf ("%d\t",mat [r][c]);
    }
}





    return(0);
}