#include<stdio.h>
#include<stdlib.h>

FILE *input, *output;

void control()
{
    if (fopen ("./in.txt", "r") == NULL)
    {
        printf ("\n\nFile inesistente!!!\n\n");
        exit(1);
    }
}

void clean()
{
    remove ("./out.txt");
}

void copy()
{
    char riga[10000];
    while (! feof(input))
    {
        fgets (riga, 10000, input);
        fprintf (output, "%s", riga);
    }
}

int main()
{
    control();
    clean();

    input = fopen ("./in.txt", "r");
    output = fopen ("./out.txt", "a");

    copy();
    
    fclose(input);
    fclose(output);

    return 0;
}