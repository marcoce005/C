#include<stdio.h>

void main()
{

int b,h,x,y,r,c,max=0;

printf ("\n\nInserire le dimensioni di una matrice");
printf ("\n\nLa base della matrice e':\t");
scanf ("%d",&b);
printf ("\nL'altezza della matrice e':\t");
scanf ("%d",&h);

int mat[b] [h],cont=0;
int coor_max_x,coor_max_y;

printf ("\n\nInserire un gap di numeri");
printf ("\n\nNumero iniziale:\t");
scanf ("%d",&x);
printf ("\nNumero finale:\t");
scanf ("%d",&y);

printf ("\n\nRiempire la matrice\n");
for (r=0;r<h;r++)
{
    for (c=0;c<b;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&mat[r] [c]);
    }
}

for (r=0;r<h;r++)
{
    for (c=0;c<b;c++)
    {
        if (mat[r] [c]<=x && mat[r] [c]>=y || mat[r] [c]<=y && mat[r] [c]>=x)
        {
            if (mat[r] [c]>=max)
            {
                max=mat[r] [c];
                coor_max_x=r;
                coor_max_y=c;
            }
        }
        else
        {
            cont++;
            printf ("\n\nIl valore nella locazione [%d;%d] non e' compreso nel gap",r,c);
        }
    }
}

if (cont==0)
{
    printf ("\n\nTutti i valori sono compresi nel gap");
}

printf ("\n\nIl numero massimo e':\t%d",max);
printf ("\nLe sue coordinate sono [%d;%d]",coor_max_x,coor_max_y);


    sleep (5);
    return(0);
}