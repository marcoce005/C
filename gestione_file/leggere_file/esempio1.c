#include<stdio.h>
#include<stdlib.h>

#define n_controllo 4

                            // r = read      w = write    r+ = read + write     w+ = write + read   a = creato se non esiste esteso se esiste
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
    remove("./MIN.txt");
}

int main()
{
    cancella();

    FILE *numeri, *MAX, *MIN;

    controllo();
    
    numeri = fopen ("./numeri.txt", "rt");
    MAX = fopen ("./MAX.txt", "at");
    MIN = fopen ("./MIN.txt", "at");
    
    int numero;

    while (! feof(numeri))      // affinche' ci sono numeri in quel file fai...
    {
        fscanf (numeri, "%d\n", &numero);
        if (numero < n_controllo)           // controllo se e' maggiore del numero dato
            fprintf (MIN, "%d\n", numero);
        else
            fprintf (MAX, "%d\n", numero);
    }
    
    fclose(MAX);          // chiudo il file
    fclose(MIN);
    fclose(numeri);
    return 0;
}