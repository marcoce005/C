#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void binary(int);

int main(int argc, char *argv[])
{
    int n;
    int *vet;

    n = atoi(argv[1]);

    vet = (int *)malloc(n * sizeof(int));
    if (vet == NULL)
    {
        printf("Allocatin Error.\n");
        exit(1);
    }

    printf("Binary Numbers:\n");
    binary(n);
    free(vet);

    return 0;
}

void binary(int n)
{
    for (int j = 0; j < n; j++)
    {
        if (fork())
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
