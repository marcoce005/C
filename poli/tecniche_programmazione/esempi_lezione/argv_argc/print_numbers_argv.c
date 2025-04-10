#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N, D;

    if (argc != 3)
    {
        printf("\nArgument error\nExecution example:\n\t%s <N> <D>\n", argv[0]);
        return -1;
    }

    N = atoi(argv[1]);
    D = atoi(argv[2]);

    for (int i = 0; i <= N; i++)
        if (i % D == 0)
            printf("\n%d", i);

    return 0;
}