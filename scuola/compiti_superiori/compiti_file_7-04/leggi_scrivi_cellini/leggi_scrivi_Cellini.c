#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void cancella()         // cancella i file vecchi
{
    remove("./testo.txt");
}

int main()
{
    FILE *Testo;

    bool ok;
    printf ("\n\nInserire 1 per modificare il testo gia' esistente, oppure inserire 0 per scrivere un altro testo:\t");
    scanf ("%d", &ok);
    fflush (stdin);
    if (ok == 0)
        cancella();

    Testo = fopen ("./testo.txt", "at");

    printf ("\n\nInserire il testo desiderato:\t");
    char testo[1000000];
    gets (testo);
    
    fprintf (Testo, "%s", testo);

    fclose (Testo);
    return 0;
}