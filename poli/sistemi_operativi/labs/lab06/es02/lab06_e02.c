#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LEN 20

typedef struct
{
    FILE *in,
        *out;
} fp;

void *sort_file(void *arg);

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Must be:\t %s [n] [strA] [strB]\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    char *str = (char *)malloc(sizeof(char) * MAX_LEN);
    pthread_t *tids = (pthread_t *)malloc(sizeof(pthread_t) * n);
    fp *vet_fp = (fp *)malloc(sizeof(fp) * n);

    for (int i = 0; i < n; i++)
    {
        sprintf(str, "%s%d.txt", argv[2], i);
        vet_fp[i].in = fopen(str, "r");

        printf("%s ->", str);

        sprintf(str, "%s%d.txt", argv[3], i);
        vet_fp[i].out = fopen(str, "w");

        printf(" %s\n", str);

        pthread_create(&(tids[i]), NULL, sort_file, &(vet_fp[i]));
    }

    for (int i = 0; i < n; pthread_join(tids[i], NULL), fclose(vet_fp[i].in), fclose(vet_fp[i].out), i++)
        ;

    free(str);
    free(vet_fp);
    free(tids);

    return 0;
}

void *sort_file(void *arg)
{
    fp *p = (fp *)arg;
    FILE *in = p->in,
         *out = p->out;

    int n;
    fscanf(in, "%d", &n);

    int vet[n];
    for (int i = 0; i < n; fscanf(in, "%d", vet + i), i++)
        ;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                vet[j] = vet[j] ^ vet[j + 1];
                vet[j + 1] = vet[j] ^ vet[j + 1];
                vet[j] = vet[j] ^ vet[j + 1];
            }
        }

    for (int i = 0; i < n; fprintf(out, "%d\n", vet[i]), i++)
        ;
}