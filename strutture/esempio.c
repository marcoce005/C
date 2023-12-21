#include<stdio.h>
#include<string.h>
#define per 2

struct persona
{
    char nome[20];
    char cognome[20];
    char ruolo[20];
    int anni;
    float salario;
};


void main()
{

struct persona p[per];          //p1 e p2 sono inizializzati come strutture

for (int i=0; i<per; i++)
{
    printf ("\n\nInseririre i dati della persona %d");
    printf ("\nInserire il nome:\t");
    gets (p[i].nome);

    printf ("\nInserire il cognome:\t");
    gets (p[i].cognome);

    printf ("\nInserire la professione:\t");
    gets (p[i].ruolo);

    printf ("\nInserire gli anni:\t");
    scanf ("%d", &p[i].anni);
}


printf ("\n\nPersona 1:\t%s\t%s\t%s\t%d", p[1].nome, p[1].cognome, p[1].ruolo, p[1].anni);

}