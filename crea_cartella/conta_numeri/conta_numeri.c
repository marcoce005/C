#include<stdio.h>
#include<stdlib.h>

FILE *testo, *out;

void control()
{
    if (fopen ("testo.txt", "r") == NULL)
    {
        printf ("\n\nFile non trovato");
        exit(1);
    }
}

void clean()
{
    remove ("out.txt");
}

void apri()
{
    testo = fopen ("testo.txt", "r");
    out = fopen ("out.txt", "a");
}

void cerca()
{
    char c;
    int i=0, tot=0;
    for (c = getc(testo); c != EOF; c = getc(testo))
    {
        if (c >= 48 && c <= 57)
        {
            tot += c-48;
            i++;
            fprintf (out, "%c\n", c);
        }
    }
    fclose(testo);
    testo = fopen ("testo.txt", "r");
    printf ("\n\nNel testo ci sono:\t%d numeri\nLa loro somma e':\t%d\n\n", i, tot);
    fprintf (out, "\n\nNel testo ci sono:\t%d numeri\nLa loro somma e':\t%d", i, tot);
}

void close()
{
    fclose(testo);
    fclose(out);
}

int main()
{   
    control();
    clean();
    apri();
    cerca();
    close();
    return 0;
}