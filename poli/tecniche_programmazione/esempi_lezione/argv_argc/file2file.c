#include <stdio.h>
#include <ctype.h>

void help();
void copy_file(char path_in[], char path_out[], int low, int upp);

int main(int argc, char *argv[])
{
    int lower = 0, upper = 0;
    char param = 'c';

    if (argc > 4 || argc < 2)
    {
        printf("\nArgument error\n");
        help();
        return -1;
    }

    if (argv[1][0] == '-')
        param = argv[1][1];

    switch (param)
    {
    case 'h':
        help();
        break;

    case 'l':
    case 'L':
        lower = 1;
        break;

    case 'u':
    case 'U':
        upper = 1;
        break;

    case 'c':
        break;

    default:
        printf("\nParameter error\n");
        help();
        return -1;
        break;
    }

    copy_file(argv[argc - 2], argv[argc - 1], lower, upper);

    return 0;
}

void copy_file(char path_in[], char path_out[], int low, int upp)
{
    FILE *in, *out;

    char c;

    in = fopen(path_in, "r");
    out = fopen(path_out, "w");

    if (in == NULL || out == NULL)
    {
        printf("\nFile error\n");
        fclose(in);
        fclose(out);
        return;
    }

    while (fscanf(in, "%c", &c) == 1)
        if (low)
            fputc(tolower(c), out);
        else if (upp)
            fputc(toupper(c), out);
        else
            fputc(c, out);  

    fclose(in);
    fclose(out);
}

void help()
{
    printf("------------------------------------------------------------\n");
    printf("                         m2m - Help                         \n");
    printf("------------------------------------------------------------\n");
    printf("\n");
    printf("Descrizione:\n");
    printf("  Il programma `m2m` legge un file di testo e lo riscrive\n");
    printf("  in un secondo file, con la possibilità di convertire\n");
    printf("  le lettere maiuscole in minuscole o viceversa, in base\n");
    printf("  ai flag specificati sulla linea di comando.\n");
    printf("\n");
    printf("Utilizzo:\n");
    printf("  m2m [opzione] <file_input> <file_output>\n");
    printf("\n");
    printf("Opzioni:\n");
    printf("  -l, -L    Converte tutto il testo in minuscolo\n");
    printf("  -u, -U    Converte tutto il testo in maiuscolo\n");
    printf("  -h        Visualizza questa schermata di help\n");
    printf("\n");
    printf("Esempi:\n");
    printf("  m2m -l a.txt a_minuscolo.txt\n");
    printf("      Converte il contenuto di a.txt in minuscolo\n");
    printf("      e lo salva in a_minuscolo.txt\n");
    printf("\n");
    printf("  m2m -u b.txt b_maiuscolo.txt\n");
    printf("      Converte il contenuto di b.txt in maiuscolo\n");
    printf("      e lo salva in b_maiuscolo.txt\n");
    printf("\n");
    printf("  m2m c.txt uguale_a_c.txt\n");
    printf("      Copia il contenuto di c.txt in uguale_a_c.txt\n");
    printf("      senza alcuna modifica\n");
    printf("\n");
    printf("  m2m -h\n");
    printf("      Mostra questa guida all'uso\n");
    printf("\n");
    printf("Note:\n");
    printf("  - Le opzioni -l e -L sono equivalenti, così come -u e -U\n");
    printf("  - Se non viene specificata alcuna opzione, il file viene\n");
    printf("    copiato senza modifiche\n");
    printf("\n");
    printf("------------------------------------------------------------\n");
}