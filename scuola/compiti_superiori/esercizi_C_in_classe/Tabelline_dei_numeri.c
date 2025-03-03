#include<stdio.h>

void main()
{

int i,n,j=1;

for (n=1;n<=10;n++)
{
    printf ("\nLa tabellina di %d:    ",j);
    
    for (i=1;i<=10;i++)
    {
        printf ("%d  ",n*i);
    }
    j++;
}












    sleep(5);
    return(0);
}