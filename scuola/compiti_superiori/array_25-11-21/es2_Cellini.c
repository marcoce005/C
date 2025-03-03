#include<stdio.h>

void main ()
{

int l,x,R=1,i;

printf ("\nInserire la lunghezza del vettore:\t");
scanf ("%d",&l);

int arr[l];

for (i=0;i<l;i++)
{
    printf ("\n\nInserire il numero nella cella %d:\t",i);
    scanf ("%d",&arr[i]);
    
    x=arr[i];
    int j;
    j=i;

    for (i=0;i<j;i++)
    {
        if (x==arr[i])
        {
            R=0;
        }
        
    }
}

printf ("\n\nIl valore risultante e' %d",R);

if (R==0)
{
    printf (" quindi ci sono dei numeri uguali");
}
else
{
    printf (" quindi tutti i numeri sono diversi");
}






    sleeo (5);
    return(0);
}