#include<stdio.h>
#include<string.h>

void main()
{

int arr[8],n,i=0;


while (i<8)
{    
    printf ("\nInserire il numero:\t");
    scanf ("%d",&n);
    
    if (n>0)
    {
        arr[i]=n;
        
        i++;
    }
    else
    {}
}

printf ("\n\nI numeri sono:");

i=0;

while (i<7)
{
    printf (" %d",arr[i]);
    i++;
}

printf (" %d",arr[7]);



    sleep (5);
    return (0);
}