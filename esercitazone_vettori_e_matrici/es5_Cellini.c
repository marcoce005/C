#include<stdio.h>

void main()
{

int mat_p[10] [20],mat_d[10] [20],r,c,n,x=0,y=0,w=0,k=0,cont_p=0,cont_d=0,j=0,i=0;

printf ("\n\nRiempire la matrice con numeri e verranno susddivisi in pari e dispari.\n");

for (r=0;r<10;r++)
{
    for (c=0;c<20;c++)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d",&n);

        if (n%2==0)
        {
            mat_p[w] [x]=n;
            x++;
            cont_p++;
        }
        else
        {
            mat_d[k] [y]=n;
            y++;
            cont_d++;
        }
    }
}

printf ("\n\nLa matrice dei numeri pari e':\n\n");
for (w=0;w<10;w++)
{
    for (x=0;x<20;x++)
    {
        if (j<cont_p)
        {
            printf ("%d\t",mat_p[w] [x]);
        }
        else
        {
            printf ("0\t");
        }
        j++;
    }
    printf ("\n");
}

printf ("\n\nLa matrice dei numeri dispari e':\n\n");
for (k=0;k<10;k++)
{
    for (y=0;y<20;y++)
    {
        if (i<cont_d)
        {
            printf ("%d\t",mat_d[k] [y]);
        }
        else
        {
            printf ("0\t");
        }
        i++;
    }
    printf ("\n");
}
    sleep (5);
    return(0);
}