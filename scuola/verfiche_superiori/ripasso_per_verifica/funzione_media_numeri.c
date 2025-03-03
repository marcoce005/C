#include<stdio.h>

float cal_media(int a, int b, int c, int d)
{
    float media = (a+b+c+d)/4;
    return(media);
}

void main()
{

int mat[4];
int i;
float risultato;

for (i=0;i<4;i++)
{
   printf ("\nInserire il voto:\t");
   scanf ("%d",&mat[i]);
}

risultato = cal_media (mat[0], mat[1], mat[2], mat[3]);

printf ("\n\nLa media e':\t%f",risultato);





    return(0);
}