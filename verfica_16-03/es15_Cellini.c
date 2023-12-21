#include<stdio.h>
#include<string.h>

#define n_squadre 3
#define n_giocatori 11

struct giocatori
{
    char nome[20];
    char cognome[20];
    int maglia;
}vet_giocatori[n_giocatori];

struct squadra
{
    int matricola;
    char nome[20];
    char citta[20];
    struct giocatori;
}vet_squadre[n_squadre];

void main()
{

int x, i;

for (x = 0; x < n_squadre; x++)
{
    printf ("\n\nInserire i dati della %d^ squadra", x+1);
    printf ("\nInserire la matricola della squadra:\t");
    scanf ("%d", &vet_squadre[x].matricola);
    printf ("\nInserire il nome della squadra:\t");
    scanf ("%s", vet_squadre[x].nome);
    printf ("\nInserire la citta' della squadra:\t");
    scanf ("%s", vet_squadre[x].citta);

    for (i = 0; i < n_giocatori; i++)
    {
        printf ("\n\nInserire i dati del %d^ giocatore.", i+1);
        printf ("\nInserire il nome:\t");
        scanf ("%s", vet_giocatori[i].nome);
        printf ("\nInserire il cognome:\t");
        scanf ("%s", vet_giocatori[i].cognome);
        printf ("\nInserire il numero di maglia:\t");
        scanf ("%d", &vet_giocatori[i].maglia);
    }
}

for (x = 0; x < n_squadre; x++)
{
    for (i = 0; i < n_giocatori; i++)
    {
        if (vet_giocatori[i].maglia == 10)
        {
            printf ("\nGiocatore:\t%s\t%s maglia numero %d", vet_giocatori[i].nome, vet_giocatori[i].cognome, vet_giocatori[i].maglia);
        }
    }
}

}