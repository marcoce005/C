#include<stdio.h>
#include<stdlib.h>

void controllo()
{
    if (fopen ("./numeri.txt", "rt") == NULL)
    {
        printf ("\n\nFile non trovato.");
        exit(1);
    }
}

void cancella()         // cancella i file vecchi
{
    remove("./MAX.txt");
}

int main()
{
    FILE *numeri, *MAX;

    controllo();
    cancella();

    numeri = fopen ("./numeri.txt", "rt");
    MAX = fopen ("./MAX.txt", "at");

    int numero, max = -10000;

    while (!feof(numeri))
    {
        fscanf (numeri, "%d\n", &numero);
        if (numero > max)
            max = numero;
    }

    fprintf (MAX, "Il numero massimo è:\t%d", max);

    fclose (MAX);
    fclose (numeri);
    return 0;
}