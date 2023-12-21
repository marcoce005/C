#include<stdio.h>

void main()
{

int mat[10] [10],i,n;

printf ("\n\nLa tavola Pitagorica e':\n\n");

for (n=1;n<=10;n++)
{
    for (i=1;i<=10;i++)
    {
        mat[n-1] [i-1]=n*i;
        printf ("%d\t",mat[n-1] [i-1]);
    }
    printf ("\n");
}



    sleep (5);
    return(0);
}