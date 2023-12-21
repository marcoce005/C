#include<stdio.h>
#include<string.h>

void calcola_prima_lettera(int l, char frase[l])
{
    int cont=1;
    for (int i = 1; i < l; i++)
    {
        if (frase[0] == frase[i])
        {
            cont++;
        }
    }
    printf ("\n\nLa prima lettera ovvero la '%c' viene ripetuta %d volta.", frase[0], cont);
}

void main()
{

char frase[100];

printf ("\n\nInserire la frase:\t");
gets(frase);

int l = strlen(frase);

calcola_prima_lettera(l, frase);

}