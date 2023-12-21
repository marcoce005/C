#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *out;

void clean()
{
    remove ("output.txt");
}

int main()
{
    clean();
    
    out = fopen ("output.txt", "a");

    char parola[10];
    printf ("\nInserire la stringa:\t");
    scanf ("%s", parola);

    while (! (parola[0] == '0' && parola[1] == '0' && strlen (parola) == 2))
    {
        if (parola[0] == '0')
            fprintf (out, "\n");
        else
            fprintf (out, "%s", parola);
        printf ("\nInserire la stringa:\t");
        scanf ("%s", parola);
    }
    
    fclose(out);
    return 0;
}