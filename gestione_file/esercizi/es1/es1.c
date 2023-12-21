#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void control()
{
    if (fopen ("./nomi.txt", "r") == NULL)
    {
        printf ("\n\nFile inesistente!!!\n");
        exit(1);
    }
}

void clean()
{
    remove ("./NOMI2.txt");
}

char* grande(char nome[])
{
    static char newnome[100];
    for (int i = 0; i < strlen(nome); i++)
    {
        newnome[i] = toupper(nome[i]);
    }
    return newnome;
}

int main()
{
    FILE *nomi, *NOMI2;

    control();
    clean();

    nomi = fopen ("./nomi.txt", "r");
    NOMI2 = fopen ("./NOMI2.txt", "a");

    char nome[100];

    while (! feof(nomi))
    {
        fscanf (nomi, "%s\n", nome);
        fprintf (NOMI2, "%s\n", grande(nome));
    }
    
    fclose(nomi);
    fclose(NOMI2);

    return 0;
}