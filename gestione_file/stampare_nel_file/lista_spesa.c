#include<stdio.h>
#include<stdlib.h>
                        
        // r = read      w = write    r+ = read + write     w+ = write + read   a = creato se non esiste esteso se esiste

void control(int n)
{
    if (n == 1)
    {
        remove ("./lista_spesa.txt");
    }
}

int main()
{
    FILE *spesa;
    
    char prodotto[20];

    int ok;
    printf ("\n\nInserire 0 per aggiungere dei prodotti alla vecchia lista o 1 per creare una nuova lista:\t");
    scanf_s ("%d", &ok);
    fflush(stdin);

    control(ok);

    int n_prod;
    printf ("\n\nInserire il numero di prodotti da comprare:\t");
    scanf_s ("%d", &n_prod);
    fflush(stdin);

    spesa = fopen ("./lista_spesa.txt", "at");
    
    for (int i = 0; i < n_prod; i++)
    {
        printf ("\n%d^ prodotto:\t", i+1);
        scanf_s ("%s", prodotto);

        fflush(stdin);      // pulisco il file
        fprintf (spesa, "%s\n", prodotto);     // copio nel file
    }

    fclose(spesa);          // chiudo il file
    return 0;
}