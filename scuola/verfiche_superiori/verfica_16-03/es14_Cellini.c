#include<stdio.h>

#define n_classi 5
#define n_allievi 10
#define n_prof 2


struct allievi
{
    char nome[20];
    char cognome[20];
    int sesso;
    int anni;
}vet_allievi[n_allievi];

struct prof
{
    char nome[20];
    char cognome[20];
    int sesso;
    int anni;
}vet_prof[n_prof];

struct classe
{
    struct allievi;
}vet_classi[n_classi];

void main()
{

int x, i;

for (x = 0; x < n_classi; x++)     //inserisco le classi
{
    printf ("\n\nInserire i dati della %d^ classe", x+1);
    printf ("\n\nInserire i dati dei %d allievi", n_allievi);       //inserisco gli allievi
    for (i = 0; i < n_allievi; i++)
    {
        printf ("\n\nInserire i dati della %d^ allievo", i+1);
        printf ("\nInserire il nome:\t");
        scanf ("%s", vet_allievi[i].nome);
        printf ("\nInserire il cognome:\t");
        scanf ("%s", vet_allievi[i].cognome);
        printf ("\nInserire il sesso (inserire 0 per i masschi e 1 per le femmine):\t");
        scanf ("%d", &vet_allievi[i].sesso);
        printf ("\nInserire l'eta':\t");
        scanf ("%d", &vet_allievi[i].anni);
    }

    printf ("\n\nInserire i dati dei %d maestri", n_prof);      //inserisco i docenti
    for (i = 0; i < n_prof; i++)
    {
        printf ("\n\nInserire i dati della %d^ docente", i+1);
        printf ("\nInserire il nome:\t");
        scanf ("%s", vet_allievi[i].nome);
        printf ("\nInserire il cognome:\t");
        scanf ("%s", vet_allievi[i].cognome);
        printf ("\nInserire il sesso (inserire 0 per i masschi e 1 per le femmine):\t");
        scanf ("%d", &vet_allievi[i].sesso);
        printf ("\nInserire l'eta':\t");
        scanf ("%d", &vet_allievi[i].anni);
    }
}

int tot=0, cont=0;

for (x = 0; x < n_classi; x++)
{
    for (i = 0; i < n_allievi; i++)
    {
        if (vet_allievi[i].sesso == 0)
        {
            cont++;
            tot += vet_allievi[i].anni;
        }
    }

    printf ("\n\nLa media dell'eta' dei maschi nella prima classe e' %f", tot/cont);
    tot=0;
    cont=0;
}


}