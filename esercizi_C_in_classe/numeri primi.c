#include <stdio.h>

void main()
{
int n,i,div=0;

printf ("\nQuesto programma dice quali numeri sono primi");
printf ("\n\nInserire il numero:    ");
scanf ("%d",&n);

for (i=2;i<n;i++)
{
       if (n%i==0 && i!=n)
       {
           div++;
       }
}

if (div==0)
{
    printf ("\n\nIl numero  e' primo");
}
else 
{
    printf ("\n\nIl numero non e' primo");
}



    sleep (5);
    return(0);
}