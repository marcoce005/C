#include<stdio.h>
#include<stdlib.h>

#define N 2
                            // r = read      w = write    r+ = read + write     w+ = write + read   a = creato se non esiste esteso se esiste
void controllo()
{
    if (fopen ("./es1.txt", "at") == NULL)
    {
        printf ("\n\nFile non trovato.");
        exit(1);
    }
}

int main()
{
    FILE *f;
    
    char cognome[20];
    char nome[20];
    int voto;

    controllo();
    
    f = fopen ("./es1.txt", "at");
    
    for (int i = 0; i < N; i++)
    {
        printf ("\nNome:\t");
        scanf_s ("%s", nome);
        fflush(stdin);
        printf ("Cognome:\t");
        scanf_s ("%s", cognome);
        fflush(stdin);
        printf ("Voto:\t");
        scanf_s ("%d", &voto);

        fflush(stdin);      // pulisco il file
        fprintf (f, "%s\t%s\t%d\n", nome, cognome, voto);     // copio nel file
    }

    fclose(f);          // chiudo il file
    return 0;
}