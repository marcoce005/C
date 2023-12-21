#include<stdio.h>
#include<string.h>
#define n_prod 3

struct prodotto
{
    char descrizione[20];
    int quantita;
    int scadenza;
};


void main()
{

struct prodotto p[n_prod];
int i=0, scad, quant;
char desc[20];

while (i != n_prod)
{
    printf ("\n\nInseririre i dati del %d prodotto", i+1);
    printf ("\nInserire la descrizione:\t");
    scanf ("%s", desc);

    printf ("\nInserire la quantita':\t");
    scanf ("%d", &quant);

    printf ("\nInserire la scadenza:\t");
    scanf ("%d", &scad);
    if (scad>=2022)
    {
        strcpy(p[i].descrizione, desc);
        p[i].quantita = quant;
        p[i].scadenza = scad;
        i++;
    }
}

for (i=0; i<n_prod; i++)
{
    printf ("\n\nIl %d prodotto:\t%s quantita' %d scandenza anno %d", i+1, p[i].descrizione, p[i].quantita, p[i].scadenza);
}


}