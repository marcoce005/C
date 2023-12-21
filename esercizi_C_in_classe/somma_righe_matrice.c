#include<stdio.h>

void main()
{

int l,r,c;

printf ("\n\nInserire la base della matrice:\t");
scanf ("%d",&l);

int mat[l] [l], arr[l], n=0, i=0;

printf ("\n\nRiempire la matrice. ");
for (r=0;r<l;r++)
{
    for (c=0;c<l;c++)
    {
        if (r==c)
        {
            mat[r] [c]=0;
        }
        else
        {
            printf ("\nInserire numero:\t");
            scanf ("%d",&mat[r] [c]);
        }
       
    }
}

for (r=0;r<l;r++)
{
    for (c=0;c<l;c++)
    {
        n=mat[r] [c]+n;
    }
    arr[i++]=n;
    n=0;
}
i=0;
for (c=0;c<l;c++)
{
    for (r=0;r<l;r++)
    {
        if (r==c)
        {
            mat[c] [r]=arr[i++];
        }
    }
   
}

printf ("\n\nIl risulatato e':\n");
for (r=0;r<l;r++)
{
    for (c=0;c<l;c++)
    {
        printf("\t%d",mat[r] [c]);
    }
    printf ("\n");
} 
    sleep (5);
   return(0);
}