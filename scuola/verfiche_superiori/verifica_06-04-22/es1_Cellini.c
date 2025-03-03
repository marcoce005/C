#include<stdio.h>
#include<string.h>

#define l 5

struct Autore
{
    char nome[20];
    int dato;
};


struct Autore v[l] = { {"Pirandello", 49}, {"Foscolo", 3}, {"Eco", 25}, {"Dannunzio", 32}, {"Calvino", 18} };

struct autore_inserito
{
    char nome[20];
    int dato;
}a_in;


int AggiungiDato()
{
    for (int i = 0; i < l; i++)
    {
        if (strcmp(a_in.nome, v[i].nome) == 0)
        {
            v[i].dato += a_in.dato;
            printf ("\n\nIl dato e' stato incrementato:\n%s = \t%d", v[i].nome, v[i].dato);
            return (1);
        }
    }
    return (0);
}

void finale(int ok)
{
    if (ok == 0)
        printf ("\n\nL'autore inserito non e' presente nell'elenco.\n");
    else
        printf ("\n\nL'autore inserito e' presente nell'elenco e il dato e' stato incrementato.\n");
}

int main()
{
    printf ("\n\nInserire l'Autore:\t");
    scanf ("%s", a_in.nome);
    printf ("\n\nInserire il dato:\t");
    scanf ("%d", &a_in.dato);    

    int ok = AggiungiDato();

    finale(ok);

    return 0;
}