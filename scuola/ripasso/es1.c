#include<stdio.h>

void riempi_array()
{
    int vet[5]={10,10,10,10,10};
    int n, i ,k=0 ,y=0;
    while (k<5)
    {
        printf ("\nInserire il numero:\t");
        scanf ("%d", &n);
        if (n>=0 && n<=9)
        {
            for (i=0;i<5;i++)
            {
                if (n!=vet[i])
                {
                    y++;
                }
            }
            if (y==5)
            {
                vet[k++]=n;
                y=0;
            }
            else
            {
                printf ("\n\nNumero non valido");
                y=0;
            }
        }
        else
        {
            printf ("\n\nNumero non valido");
        }
    }
    printf ("\n\nL'array e':\t");
    for (i=0;i<5;i++)
    {
        printf ("%d\t",vet[i]);
    }
}


void main()
{

int vet[5];

printf ("\n\nRiempire l'array");
riempi_array();


}