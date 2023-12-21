#include<stdio.h>

void romano(int n)
{
    while(n!=0)
    {
        if (n==4)
        {
            printf (" IV");
            n=0;
        }
        else if (n==9)
        {
            printf (" IX");
            n=0;
        }
        if (n-1000>=0)
        {
            printf (" M");
            n -= 1000;
        }
        else if (n-500>=0)
        {
            printf (" D");
            n -= 500;
        }
        else if (n-100>=0)
        {
            printf (" C");
            n -= 100;
        }
        else if (n-50>=0)
        {
            printf (" L");
            n -= 50;
        }
        else if (n-10>=0)
        {
            printf (" X");
            n -= 10;
        } 
        else if (n-5>=0)
        {
            printf (" V");
            n -= 5;
        }
        else if (n-1>=0)
        {
            printf (" I");
            n -= 1;
        } 
    }
}

void main()
{
int n;

printf ("\n\nInseire il numero decimale:\t");
scanf ("%d",&n);

printf ("\n\nIl numero decimale %d in romano e':\t",n);
romano(n);

    return(0);
}