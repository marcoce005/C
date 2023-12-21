#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct dictonary {      // dizionario dei risultati
    int key;        // somma possibile
    int value;          // numero di volte che e' apparsa
};

int som_digits(int n) {     // sommo le cifre del numero
    int tot = 0;
    while (n != 0) {
        tot += n % 10;      // sommo l'ultima cifra
        n /= 10;        // rimuovo l'ultima cifra
    }
    return tot;
}

int last_number(int n) {        // calcolo la somma massima che si puo' avere
    int tmp = n, digits = 0;
    do {
        tmp /= 10;              // conto il numero di cifre
        digits++;
    } while (tmp != 0);

    // arrivo alla somma di cifre massime in quel range
    int number =  n - ((n + 1) - (pow(10, (double)(digits - 1)) * (int)(n / pow(10, digits - 1))));
    /* numero iniziale - [ (numero iniziale + 1) - (10^(cifre-1) * prima cifra) ] */
    return som_digits(number);
}

void fill_struct(struct dictonary *d, int limit) {
    for (int i = 0; i < limit + 1; i++) {       // da 1 alla somma massima inizializzo la struttura
        d[i].key = i + 1;
        d[i].value = 0;
    }
}

void cal_probability(struct dictonary *d, int pages) {
    for (int i = 1; i < pages + 1; i++) {       // per ogni numero da 1 a n_pagine 
        d[som_digits(i) - 1].value++;     // sommo le cifre e incremento la relativa parte del dizionario
    }
}

void print(struct dictonary *d, int limit, int pages) {
    printf("\nProbability:\n");
    for (int i = 0; i < limit; i++) {
        printf(" - %d\t-->\t%f %%\n", d[i].key, ((double)d[i].value / pages) * 100);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {                // controllo il passaggio del nummero di pagine
        printf("%s <numero pagine libro>", argv[0]);
        exit(1);
    }

    int end = last_number(atoi(argv[1]) + 1);
    struct dictonary d[end + 1];        // crea il dizionario che conterra' i risultati
    fill_struct(d, end);            // inizializzo il dizionario key incrementale e value == 0
    cal_probability(d, atoi(argv[1]));      // calcolo la probabilita' per ogni somma possibile
    print(d, end, atoi(argv[1]));               // stampo i risulti

    return 0;
}