#include<stdio.h>

void main()
{

int n, tot=0;

printf  ("\nInserire il numero:\t");
scanf ("%d",&n);

while (n>0)
{
    tot=tot+n;
    printf  ("\nInserire il numero:\t");
    scanf ("%d",&n);
}

printf  ("\n\nIl totale e':\t%d",tot);

    return(0);
}