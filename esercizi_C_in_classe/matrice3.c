#include<stdio.h>

main()
{

int r,c,y;

printf ("\n\nInserisce dei numeri delle matrici");
printf ("\nLe righe sono:\t");
scanf ("%d",&r);
printf ("\nLe colonne sono:\t");
scanf ("%d",&c);

int i,m1 [r] [c],m2 [r] [c],m3 [r] [c];

printf ("\nInserire i numeri della prima matrice");
for (i=0;i<c;i++)
{
    for (y=0;y<r;y++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&m1[i] [y]);
    }
    
}
printf ("\nInserire i numeri della secondo matrice");
for (i=0;i<c;i++)
{
    for (y=0;y<r;y++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&m2[i] [y]);
    }
    
}

printf ("\nLa matrice e':\n");

for (i=0;i<c;i++)
{
    for (y=0;y<r;y++)
    {
     m3 [i] [y]=m1[i] [y]*m2[i] [y];   
    }
    
}

printf ("\nIl prodotto dei delle matrici e':\n");
for (i=0;i<c;i++)
{
    for (y=0;y<r;y++)
    {
     printf ("%d\t",m3 [i] [y]);   
    }
    printf ("\n");   
}
    

    return(0);
}
