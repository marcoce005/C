#include<stdio.h>
#include<stdlib.h>

FILE *numeri;

void control()
{
    if (fopen ("./numeri.txt", "r") == NULL)
    {
        printf ("\n\nNo FIle\n\n");
        exit(1);
    }
}

int countline()
{
    int tot=0;
    char c;
    for (c = getc(numeri); c != EOF; c = getc(numeri))
        if (c == '\n')
            ++tot;

    fclose(numeri);
    numeri = fopen ("./numeri.txt", "r");

    return tot+1;
}

int main()
{
    control();

    numeri = fopen ("./numeri.txt", "r");

    printf ("\n\nIl file ha %i righe\n\n", countline());

    fclose(numeri);

    return 0;
}