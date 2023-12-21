#include<stdio.h>
#include<stdlib.h>

FILE *stampa;

void apri()
{
    stampa = fopen ("stampa.txt", "a");
}

void riempi()
{
    printf ("\n\nInserire 0 per smettere di scrivere sul file");
    char str[100];
    while (1)
    {
        printf ("\nInserire testo:\t");
        fgets (str, 100, stdin);
        if (str[0] == '0')
            exit(1);
        fprintf (stampa, "%s", str);
    }    
}

void close()
{
    fclose (stampa);
}

void clean()
{
    remove ("stampa.txt");
}

int main()
{
    clean();
    apri();
    riempi();
    close();
    return 0;
}