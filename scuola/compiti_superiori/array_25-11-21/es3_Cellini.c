#include<stdio.h>
#include<math.h>

void main ()
{

int n,y,i=0,V[5],R[5];



while (i<5)
{
    printf ("\nInserire un numero compreso tra 0 e 100:\t"); 
    scanf ("%d",&n);
    
    if (n>0 && n<100)
    {
        V[i]=n;
        R[i]=pow (n,2);
        i++;
    } 
}

printf ("\n\nI numeri alla seconda compresi tra 0 e 100 sono:");

for (y=0;y<5;y++)
{
    printf ("\t%d",R[y]);
}

    sleep (5);
    return(0);
}