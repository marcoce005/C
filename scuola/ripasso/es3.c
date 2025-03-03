#include<stdio.h>

void par_dispar(int n)
{
    if (n%2==0)
    {
        printf ("\n\nIl numero e' pari.");
    }
    else 
    {
        printf ("\n\nIl numero e' dispari.");
    }
}

void fatt(int n)
{
    double tot=1;
    for (int i=1; i<=n; i++)
    {
        tot *= i; 
    }
    printf ("\n\nIl fattoriale di %d e':\t%lf", n, tot);
}

void primo(int n)
{
    int div=0;
    for (int i=2; i<n; i++)
    {
       if (n%i==0 && i!=n)
       {
           div++;
       }
    }
    if (div==0)
    {   
        printf ("\n\nIl numero %d e' primo",n);
    }
    else 
    {
        printf ("\n\nIl numero %d non e' primo",n);
    }
}


void main()
{

int n;

printf ("\n\nInserire il numero:\t");
scanf ("%d",&n);
if (n>=0)
{
    par_dispar(n);
    fatt(n);
    primo(n);
}
else 
{
    printf ("\n\nNumero non valido.");
}


}