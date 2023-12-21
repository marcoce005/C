#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *input, *output;

void control()
{
    if (fopen ("./input.txt", "r") == NULL)
    {
        printf ("\n\nFile di origine inesistente!!!\n\n");
        exit(1);
    }
}

void clean()
{
    remove ("./output.txt");
}

void copy()
{
    char riga[1000000];
    while (! feof(input))
    {
        fgets (riga, 1000000, input);
        for (int i = 0; i < strlen(riga); i++)
        {
            if (riga[i] == '\n')
                riga[i] = '\0';
        }
        fprintf (output, "%s\t(%ld)\n", riga, strlen(riga));
    }
}

int main()
{
    control();
    clean();

    input = fopen ("./input.txt", "r");
    output = fopen ("./output.txt", "a");

    copy();

    fclose(input);
    fclose(output);

    return 0;
}