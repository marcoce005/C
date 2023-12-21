#include<stdio.h>
#include<string.h>
#include<math.h>

void main()
{
int n,i;

printf ("\nInserire quante celle creare:\t");
scanf ("%d",&n);

int num[n];
int quad[n];
int cubo[n];

for (i=0;i<n;i++)
{
    printf ("\n\nInserire il numero:\t");
    scanf ("%d",&num[i]);
    quad[i]=pow(num[i],2);
    cubo[i]=pow(num[i],3);
}

printf ("\n\nI quadrati sono:\t");

for (i=0;i<n;i++)
{
    printf (" %d",quad[i]);
}

printf ("\n\nI cubi sono:\t");

for (i=0;i<n;i++)
{
    printf (" %d",cubo[i]);
}

sleep (5);
return (0);

}