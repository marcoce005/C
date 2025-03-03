#include<stdio.h>

void main()
{

char nome[12], ch;
int i, n, N=0;

printf ("\n\nInserisci il nome:\t");
ch = getchar();         //prende i caratteri nel nome 

while (ch !='\n' && N<12)
{
    nome[N++] = ch;         //li assegna nel vettore
    ch = getchar();
}

printf ("\n\nIl nome e':\t");
for (i=0;i<N;i++)
{
    if (nome[i]=='t')               //sostituisco delle lettere
    {
        nome[i]='s';
    }
    putchar(nome[i]);                   //visualizzo il nome 
}

    return(0);
}