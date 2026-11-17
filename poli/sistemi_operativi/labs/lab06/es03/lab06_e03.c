#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LEN_STR 20
#define N_NUMBERS_IN_FILE 10

typedef struct
{
    FILE *in;
    int *vet;
} fp;

void *sort_file(void *arg);
void free_mat(int **m, int n);
void merge(int *a, int *b, int n_a); // n_b == N_NUMBERS_IN_FILE

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Must be:\t %s [n] [strA] [strB]\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    char *str = (char *)malloc(sizeof(char) * MAX_LEN_STR);
    pthread_t *tids = (pthread_t *)malloc(sizeof(pthread_t) * n);
    fp *vet_fp = (fp *)malloc(sizeof(fp) * n);
    int **mat = (int **)malloc(sizeof(int *) * n);
    int *sorted = (int *)malloc(sizeof(int) * n * N_NUMBERS_IN_FILE);

    for (int i = 0; i < n; i++)
    {
        sprintf(str, "%s%d.txt", argv[2], i);
        vet_fp[i].in = fopen(str, "r");

        printf("%s\n", str);

        mat[i] = (int *)malloc(sizeof(int) * N_NUMBERS_IN_FILE);
        vet_fp[i].vet = mat[i];

        pthread_create(&(tids[i]), NULL, sort_file, &(vet_fp[i]));
    }

    for (int i = 0; i < n; pthread_join(tids[i], NULL),
             fclose(vet_fp[i].in),
             merge(sorted, mat[i], N_NUMBERS_IN_FILE * i),
             i++)
        ;

    sprintf(str, "%s0-%d.txt", argv[3], n - 1);
    FILE *fp_out = fopen(str, "w");
    for (int i = 0; i < N_NUMBERS_IN_FILE * n; fprintf(fp_out, "%d\n", sorted[i]), i++)
        ;
    fclose(fp_out);

    free(str);
    free(vet_fp);
    free(tids);
    free_mat(mat, n);
    free(sorted);

    return 0;
}

void merge(int *a, int *b, int n_a)
{
    int *tmp = (int *)malloc(sizeof(int) * (n_a + N_NUMBERS_IN_FILE));

    for (int i = 0, j = 0, k = 0; k < n_a + N_NUMBERS_IN_FILE; k++)
    {
        if (i >= n_a)
            tmp[k] = b[j++];
        else if (j > N_NUMBERS_IN_FILE)
            tmp[k] = a[i++];
        else
            tmp[k] = a[i] <= b[j] ? a[i++] : b[j++];
    }

    for (int i = 0; i < (n_a + N_NUMBERS_IN_FILE); a[i] = tmp[i], i++)
        ;

    free(tmp);
}

void *sort_file(void *arg)
{
    fp *p = (fp *)arg;
    FILE *in = p->in;
    int *vet = p->vet;

    fscanf(in, "%*d"); // skip the first number [it's the amount of numbers in the file]

    for (int i = 0; i < N_NUMBERS_IN_FILE; fscanf(in, "%d", vet + i), i++)
        ;

    for (int i = 0; i < N_NUMBERS_IN_FILE - 1; i++)
        for (int j = 0; j < N_NUMBERS_IN_FILE - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                vet[j] = vet[j] ^ vet[j + 1];
                vet[j + 1] = vet[j] ^ vet[j + 1];
                vet[j] = vet[j] ^ vet[j + 1];
            }
        }
}

void free_mat(int **m, int n)
{
    for (int i = 0; i < n; free(m[i]), i++)
        ;
    free(m);
}