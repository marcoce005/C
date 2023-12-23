#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int pari[36] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
int dispari[36] = {1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 2, 4, 18, 20, 11, 3, 6, 8, 12, 14, 16, 10, 22, 25, 24, 23};

int modulo(int tot_finale)
{
    int r = (tot_finale % 26) + 65;
    return(r);
}

int somma_dispari(int vet_dispari[])
{
    int tot=0, loc;
    for (int i = 0; i < 8; i++)
    {
        if (vet_dispari[i] >= 48 && vet_dispari[i] <= 57)
            loc = vet_dispari[i] - 48;
        else
            loc = vet_dispari[i] - 65 + 10;
        tot += dispari[loc];
    }
    return(tot);
}

int somma_pari(int vet_pari[])
{
    int tot=0, loc;
    for (int i = 0; i < 7; i++)
    {
        if (vet_pari[i] >= 48 && vet_pari[i] <= 57)
            loc = vet_pari[i] - 48;
        else
            loc = vet_pari[i] - 65 + 10;
            
        tot += pari[loc];
    }
    return(tot);
}

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf ("\n\nInserire un codice fiscale.");
        exit(1);
    }

    if (strlen(argv[1]) != 15)
    {
        printf ("\n\nCodice errato (troppo corto o troppo lungo).");
        exit(1);
    }

    int i; 
    char *n = argv[1];
    
    for (i = 0; i < 15; i++)
    {
        n[i] = toupper(n[i]);
    }

    int vet_pari[7], vet_dispari[8], p=0, d=0;

    for (i = 1; i < 16; i++)
    {
        if (i % 2 == 0)
            vet_pari[p++] = n[i-1];
        else
            vet_dispari[d++] = n[i-1];
    }
    
    int tot_finale = somma_pari(vet_pari) + somma_dispari(vet_dispari);
    int risultato = modulo(tot_finale);

    printf ("\n\nIl bit di controllo del codice fiscale e' %c il codice completo e' quindi %s%c", risultato, n, risultato);
}
