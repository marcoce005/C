#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void init_mpz(mpz_t *num, int n) {
    mpz_init(*num);
    mpz_set_ui(*num, n);
}

void my_pow(int b, int e, mpz_t *result){
    mpz_t base;
    mpz_inits(base, result, NULL);
    mpz_set_ui(base, b);
    mpz_pow_ui(*result, base, e);
}

int decifr (int N, int c, int N_priv){
    mpz_t pow_result, result, n;
    init_mpz(&result, 0);
    init_mpz(&n, N);
    my_pow(c, N_priv, &pow_result);
    mpz_mod(result, pow_result, n);
    return mpz_get_ui(result);
}

int main(int argc, char **argv){
    if (argc != 4)
    {
        printf("%s <N> <messaggio_cifrato> <N_priv>", argv[0]);
        return 0;
    }

    int N = atoi(argv[1]);
    int N_priv = atoi(argv[3]);
    printf("\n%s --> ", argv[2]);
    char* c = argv[2];
    char* c2 = strtok(c, ",");

    
    while (c2 != NULL)
    {
        printf("%c", decifr(N, atoi(c2), N_priv));
        c2 = strtok(NULL, ",");
    }
    printf("\n");
    return 0;
}