#include<stdio.h>
#include<string.h>
#define per 3

struct persona
{
    char nome[20];
    char cognome[20];
    char sesso[20];
    int anni;
};


void main()
{

struct persona p[per];

for (int i=0; i<per; i++)
{
    printf ("\n\nInseririre i dati della persona %d", i+1);
    printf ("\nInserire il nome:\t");
    scanf ("%s", p[i].nome);

    printf ("\nInserire il cognome:\t");
    scanf ("%s", p[i].cognome);

    printf ("\nInserire il sesso:\t");
    scanf ("%s", p[i].sesso);
    
    printf ("\nInserire gli anni:\t");
    scanf ("%d", &p[i].anni);
}

int cont_f=0;

for (int i=0; i<per; i++)
{
    if ((strcmp(p[i].sesso, "femmina")  == 0) || (strcmp(p[i].sesso, "Femmina")  == 0) || (strcmp(p[i].sesso, "FEMMINA")  == 0))
    {
        cont_f++;
    }
}

int vet[cont_f], k=0;

for (int i=0; i<per; i++)
{
    if ((strcmp(p[i].sesso, "femmina")  == 0) || (strcmp(p[i].sesso, "Femmina")  == 0) || (strcmp(p[i].sesso, "FEMMINA")  == 0))
    {
        vet[k++] = i;
    }
}

for (int i=0; i<cont_f; i++)
{
    printf ("\nPersona %d:\t%s\t%s\t%d\t%s", i+1, p[vet[i]].nome, p[vet[i]].cognome, p[vet[i]].anni, p[vet[i]].sesso);
}


}