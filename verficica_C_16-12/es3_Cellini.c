#include<stdio.h>
#define l 10

void main()
{

int arr[l],i,x=1;

for (i=0;i<l-2;i++)
{
    arr[i]=x++;
}

printf ("\n\nRiempire gli ultimi due valori\n");
for (i=l-2;i<l;i++)
{
    printf ("\nInserire il numero:\t");
    scanf ("%d",&arr[i]);
}

int i=0,cont=0;

while (cont!=0)
{
    if (arr[i]<=arr[l-2])
    {}
    else
    {
        if (arr[i]=='\0')
        {}
        else
        {
            arr[i+9]=arr[i+8];
            arr[i+8]=arr[i+7];
            arr[i+7]=arr[i+6];
            arr[i+6]=arr[i+5];
            arr[i+5]=arr[i+4];
            arr[i+4]=arr[i+3];
            arr[i+3]=arr[i+2];
            arr[i+2]=arr[i+1];
            arr[i+1]=arr[i];
        }
        cont++;
    }
}



printf ("\n\nL'arrey completo e':\t");

for (i=0;i<l;i++)
{
    printf ("%d\t",arr[i]);
}








    return(0);
}