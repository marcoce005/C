#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define n_al 4

struct classe
{
    char nome[20];
    char congnome[20];
    int voto;
}vet_alunno[n_al];

void leggi ()
{
    printf ("\n\nInserire tutti gli alunni con i rispettivi voti.");
    for (int i = 0; i < n_al; i++)
    {
        printf ("\nInserire il nome del %d alunno:\t", i+1);
        scanf_s ("%s", vet_alunno[i].nome);
        printf ("\nInserire il cognome del %d alunno:\t", i+1);
        scanf_s ("%s", vet_alunno[i].congnome);
        printf ("\nInserire il voto del %d alunno:\t", i+1);
        scanf_s ("%d", &vet_alunno[i].voto);
        if (vet_alunno[i].voto > 10 || vet_alunno[i].voto < 2)
        {
            printf ("\n\nVOTO NON VALIDO RIPROVARE.");
            exit(1);    
        }
    }
}

float media()
{
    int tot = 0;
    for (int i = 0; i < n_al; i++)
        tot += vet_alunno[i].voto;

    return (float)tot / n_al;
}

void stampa ()
{
    for (int i = 0; i < n_al; i++)
    {
        printf ("\n%d)\t%s\t%s", i+1, vet_alunno[i].congnome, vet_alunno[i].nome);
    }
}

int main()
{   
    leggi();
    stampa();
    printf ("\nMedia = %f", media());
    return 0;
}