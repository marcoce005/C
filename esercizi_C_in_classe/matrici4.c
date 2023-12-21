#include<stdio.h>

main()
{

int i,r,y,n;

printf ("\n\nInserisce la diagonale di un quadrato");
printf ("\nI lati sono:\t");
scanf ("%d",&r);

int m [r] [r];

printf ("\nInserire il numero di cui si vuole la diagonale:\t");
scanf ("%d",&n);

for (i=0;i<r;i++)
{
    for (y=0;y<r;y++)
    {
        if (i==y)
        {
            m [i] [y]=n;
        }
        else
        {
            m [i] [y]=0;        
        }
    }
}


for (i=0;i<r;i++)
{
    for (y=0;y<r;y++)
    {
        printf ("%d\t",m [i] [y]);
    }
    printf ("\n");
}





    

    return(0);
}
