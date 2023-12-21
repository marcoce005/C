#include<stdio.h>
#include<stdlib.h>

FILE *numeri;

void control()
{
    if (fopen ("./numeri.txt", "r") == NULL)
    {
        printf ("\n\nFile inesistente!!!\n\n");
        exit(1);
    }
}

int cont(int n)
{
    int tot=0, x;
    while (! feof(numeri))
    {
        fscanf (numeri, "%d\n", &x);
        if (n == x)
            tot++;
    }
    return tot;
}

int main()
{
    control();

    numeri = fopen ("./numeri.txt", "r");

    int n;
    printf ("\n\nInserire il numero da ricercare nel file 'numeri.txt':\t");
    scanf ("%d", &n);

    printf ("\n\nIl numero %d comapre %d volte nel file 'numeri.txt\n\n", n, cont(n));
    
    fclose(numeri);

    return 0;
}