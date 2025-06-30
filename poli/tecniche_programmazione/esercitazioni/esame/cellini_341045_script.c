#include <stdio.h>

typedef struct
{
    char id[30];
    int ingressi;
} attivita;

typedef struct
{
    char id[7];
    attivita *elenco;
    int n;
} bambino;

void raggruppaBambini(bambino b[], int n, int conteggi[10]);
void attivitaPreferite(bambino b[], int n, attivita *preferite[]);
int piuAttivi(bambino b[], int n, int min, bambino *selezionati[]);

int main()
{
    return 0;
}

void raggruppaBambini(bambino b[], int n, int conteggi[10])
{
    int i, n_attivita;
    for (i = 0; i < n; i++)
    {
        n_attivita = b[i].n;
        if (n_attivita > 45)
            conteggi[9]++;
        else
            conteggi[n_attivita / 5]++;
    }
}

void attivitaPreferite(bambino b[], int n, attivita *preferite[])
{
    int i, j, max, n_attivita;
    for (i = 0; i < n; i++)
    {
        max = 0;
        n_attivita = b[i].n;
        for (j = 1; j < n_attivita; j++)
            if (b[i].elenco[j].ingressi > b[i].elenco[max].ingressi)
                max = j;
        preferite[i] = &b[i].elenco[max];
    }
}

int piuAttivi(bambino b[], int n, int min, bambino *selezionati[])
{
    int i, n_attivita, selected = 0;
    for (i = 0; i < n; i++)
    {
        n_attivita = b[i].n;
        if (n_attivita >= min)
            selezionati[selected++] = &b[i];
    }
    return selected;
}