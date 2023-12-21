#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n_parite 3

struct partite
{
    char moneta[5];
    int d1;
    int d2;
}vet_partite[n_parite];

int alto(int p1, int p2)
{
    if (p1 > p2)
        return(0);
    else if (p2 > p1)
        return(1);
    else
        return(2);
}

int basso(int p1, int p2)
{
    if (p1 > p2)
        return(1);
    else if (p2 > p1)
        return(0);
    else
        return(2);
}

int main()
{
    int r, g1=0, g2=0;
    for (int i = 0; i < n_parite; i++)
    {
        printf ("Inserire i dati della %d^ partita.", i+1);
        printf ("\nInserire il risultato della moneta testa o croce (tutto minuscolo):\t");
        scanf_s ("%s", vet_partite[i].moneta);
        if (strcmp(vet_partite[i].moneta, "testa") != 0 && strcmp(vet_partite[i].moneta, "croce") != 0)
        {
            printf ("\n\nFaccia della moneta non valida.");
            exit(1);
        }
        printf ("Inserire del primo dado (da 1 a 6):\t");
        scanf_s ("%d", &vet_partite[i].d1);
        if (vet_partite[i].d1 < 1 || vet_partite[i].d1 > 6)
        {
            printf ("\n\nFaccia del dado non valida.");
            exit(1);
        }
        printf ("Inserire del secondo dado (da 1 a 6):\t");
        scanf_s ("%d", &vet_partite[i].d2);
        if (vet_partite[i].d2 < 1 || vet_partite[i].d2 > 6)
        {
            printf ("\n\nFaccia del dado non valida.");
            exit(1);
        }

        if (strcmp(vet_partite[i].moneta, "testa") == 0)
            r = alto(vet_partite[i].d1, vet_partite[i].d2);
        else
            r = basso(vet_partite[i].d1, vet_partite[i].d2);

        if (r == 0)
            g1++;
        else if (r ==1)
            g2++;
    }

    if (g1 > g2)
        printf ("\n\nIl vincitore e' il giocatore numero 1.");
    else if (g2 > g1)
        printf ("\n\nIl vincitore e' il giocatore numero 2.");
    else
        printf ("\n\nPareggio.");
}