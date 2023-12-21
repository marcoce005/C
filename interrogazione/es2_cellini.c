#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define n_corsi 3

struct classe
{
    char nome_corso[20];
    char nome_docente[20];
    int voto_medio;
}V[n_corsi];

void leggi ()
{
    printf ("\n\nInserire tutti i corsi con i rispettivi dati.\n");
    for (int i = 0; i < n_corsi; i++)
    {
        printf ("\nInserire il nome del %d^ corso:\t", i+1);
        scanf_s ("%s", V[i].nome_corso);
        printf ("Inserire il nome del docente del %d^ corso:\t", i+1);
        scanf_s ("%s", V[i].nome_docente);
        printf ("Inserire il voto medio del %d^ corso:\t", i+1);
        scanf_s ("%d", &V[i].voto_medio);
        if (V[i].voto_medio > 30 || V[i].voto_medio < 0)
        {
            printf ("\n\nVOTO NON VALIDO RIPROVARE.");
            exit(1);    
        }
    }
}

void piu_facile()
{
    int max = -1, loc;
    for (int i = 0; i < n_corsi; i++)
        if (V[i].voto_medio > max)
        {
            max = V[i].voto_medio;
            loc = i;
        }
    printf ("\n\nIl corso pi' facile e' il %d^ corso quindi il corso di %s gestito dal Prof. %s ed un voto medio pari ad %d", loc+1, V[loc].nome_corso, V[loc].nome_docente, V[loc].voto_medio);
}

int main()
{   
    leggi();
    piu_facile();
    return 0;
}