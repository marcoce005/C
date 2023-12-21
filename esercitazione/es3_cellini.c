#include<stdio.h>

#define n_alberghi 3

struct albergo
{
    char tipo_albergo;
    int n_stanze;
}alb[n_alberghi];

void confronto()
{
    int cont=1, stanze_alberghi_uguali[n_alberghi], j=0;
    char valore;

    for (int i = 0; i < n_alberghi; i++)
    {
        for (int k = i+1; k < n_alberghi; k++)
        {
            if (alb[i].tipo_albergo == alb[k].tipo_albergo)
            {
                cont++;
                stanze_alberghi_uguali[j++] = alb[i].n_stanze;
                stanze_alberghi_uguali[j++] = alb[k].n_stanze;
                valore = alb[i].n_stanze;
            }
        }
        if (cont > 1)
        {
            break;
        }
    }

    printf ("\n\nGli alberghi dello stesso tipo sono %d ed hanno rispettivament", cont);
    for (int i = 0; i < cont; i++)
    {
        printf ("e %d ", stanze_alberghi_uguali[i]);
    }
    printf ("stanze e sono della tipologia %c", valore);
}

void main()
{

for (int i = 0; i < n_alberghi; i++)
{
    printf ("\nInserire i dati del %d albergo", i+1);
    printf ("\nTipo di albergo:\t");
    scanf ("%s", &alb[i].tipo_albergo);
    printf ("Numero di stanze:\t");
    scanf ("%d", &alb[i].n_stanze);
}

confronto();

}