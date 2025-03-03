#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *dettagli, *out;

void clean()
{
    remove ("output.txt");
}

void apri()
{
    dettagli = fopen ("dettagli.txt", "r");
    out = fopen ("output.txt", "a");
}

void close()
{
    fclose (dettagli);
    fclose (out);
}

int main()
{
    clean();
    apri();

    char c;
    int n[7], i = 0;
    for (c = getc(dettagli); c != EOF; c = getc(dettagli))
    {
        fscanf (dettagli, "%i\n", &n[i++]);
    }

    fprintf (out, "Il treno delle %d e %d porta un ritardo di %d minuti. Chissà se mi rimborseranno i %d,%d euro del biglietto? Il giorno %d/%d/2007 ci sarà un’altra riunione alle %d.", n[5], n[3], n[6], n[2], n[4], n[1], n[3], n[0]);  

    close();
    return 0;
}