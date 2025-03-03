#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *in, *out;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void clean()
{
    remove ("output.txt");
}

void apri()
{
    in = fopen ("input.txt", "r");
    out = fopen ("output.txt", "a");
}

void close()
{
    fclose (in);
    fclose (out);
}

int main()
{
    clean();
    apri();

    char c;
    int n[100], i = 0, n2[100], cont = 0;
    while (! feof (in))
    {
        fscanf (in, "%i ", &n[i++]);
        cont++;
    }

    for (i = 1; i < cont; i++)
        n2[i-1] = n[i];
        

    qsort (n2, cont-1, sizeof (int), cmpfunc); 

    for (i = 0; i < cont-1; i++)
        fprintf (out, "%d ", n2[i]);

    close();
    return 0;
}