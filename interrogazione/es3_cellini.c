#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 3
#define V 7

struct nomi
{
    int matricola;
    char nome[20];
    char congnome[20];
}nome[M];

struct voti
{
    int matricola;
    char esame[20];
    int voto;
}voto[V];

void leggi ()
{
    printf ("\n\nRiempire la struttuta con i nomi.n\n");
    for (int i = 0; i < M; i++)
    {
        printf ("\nInserire numero di matricola del %d alunno:\t", i+1);
        scanf_s ("%d", &nome[i].matricola);
        printf ("\nInserire il nome del %d alunno:\t", i+1);
        scanf_s ("%s", nome[i].nome);
        printf ("\nInserire il cognome del %d alunno:\t", i+1);
        scanf_s ("%s", nome[i].congnome);
    }
    printf ("\n\nRiempire la struttuta con i rispettivi voti.n\n");
    for (int i = 0; i < V; i++)
    {
        printf ("\nInserire il numero di matricola %d alunno:\t", i+1);
        scanf_s ("%d", &voto[i].matricola);
        printf ("\nInserire il nome dell'esame %d alunno:\t", i+1);
        scanf_s ("%s", voto[i].esame);
        printf ("\nInserire il voto del %d alunno:\t", i+1);
        scanf_s ("%d", &voto[i].voto);
        if (voto[i].voto > 30 || voto[i].voto < 0)
        {
            exit(1);
            printf ("\n\nVOTO NON VALIDO.");
        }
    }
}

int *somma()
{
    int tot[M];
    int *d=malloc(8192);
    
    for (int i = 0; i < M; i++)
    {
        for (int y = 0; y < V; y++)
        {
            if (nome[i].matricola == voto[y].matricola)
                tot[i] += voto[y].voto;
        }
    }
    memcpy(d,tot,8192);
    return d;
}

void stampa(int *somme[])
{
    for (int i = 0; i < M; i++)
    {
        printf ("Matricola %d somma voti:%d\t", nome[i].matricola, somme[i]);
    }
}

int main()
{   
    leggi();
    int *arr_somme = malloc(8192);
    memcpy(arr_somme,somma(),8192);
    stampa(arr_somme);  
    return 0;
}