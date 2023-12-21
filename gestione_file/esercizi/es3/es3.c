#include<stdio.h>
#include<stdlib.h>

FILE *n1, *n2, *out;

void control()
{
    if (fopen ("./n1.txt", "r") == NULL || fopen ("./n2.txt", "r") == NULL)
    {
        printf ("\n\nFIle non trovato!!!\n\n");
        exit(1);
    }
}

void clean()
{
    remove ("./out.txt");
}

int cont()
{
    int tot=0;
    while (!feof (n1))
    {
        tot++;
    }
    while (!feof (n2))
    {
        tot++;
    }
    printf ("%d\n", tot);
    return tot;
}

void work()
{
    int numeri[cont()], i=0;

    while (!feof (n1))
    {
        fscanf (n1, "%d\n", &numeri[i++]);
    }
    while (!feof (n2))
    {
        fscanf (n2, "%d\n", &numeri[i++]);
    }

    for (i = 0; i < cont(); i++)
    {
        fprintf (out, "%d\n", numeri[i]);
    }
}



int main()
{   printf ("hello");
    control();
    clean();

    n1 = fopen ("./n1.txt", "rt");
    n2 = fopen ("./n2.txt", "rt");
    out = fopen ("./out.txt", "at");

    work();

    fclose(n1);
    fclose(n2);
    fclose(out);

    return 0;
}