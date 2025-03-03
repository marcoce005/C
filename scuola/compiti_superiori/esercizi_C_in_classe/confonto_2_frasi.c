#include<stdio.h>
#include<string.h>

void main()
{

char frase1[]="abca";
char frase2[]="aaca";
int x;

x=strcmp (frase1,frase2);

if (x==0)
{
    printf ("\nSono Uguali");
}
else if (x>0)
{
    printf ("\nLa prima frase e maggiore della seconda");
}
else
{
    printf ("\nLa seconda frase e maggiore della prima");
}
    return(0);
}