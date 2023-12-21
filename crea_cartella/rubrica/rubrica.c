#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

FILE *rubrica, *new_rubrica;

struct dati
{
    char nome[50];
    char cognome[50];
    long int numero;
};

int countline()
{
    rubrica = fopen ("./rubrica.txt", "r");
    int tot=0;
    char c;
    for (c = getc(rubrica); c != EOF; c = getc(rubrica))
        if (c == '\n')
            ++tot;
    fclose (rubrica);
printf ("\nciao\n");
    return tot+1;
}

void print (struct dati d[], size_t l)
{
    int i;
    while (! feof(rubrica))
    {
        fprintf (new_rubrica, "%s\t%s\t%li\n", d[i].nome, d[i].cognome, d[i++].numero);
    }
}

void new_dir()
{
    char *nome = "New_rubrica";
    mkdir(nome, S_IRWXU);
}

void control()
{
    if (fopen ("./rubrica.txt", "r") == NULL)
    {
        printf ("\n\nFile non trovato");
        exit(1);
    }
}

void clean()
{
    remove ("New_rubrica/new_rubrica.txt");
}

void add()
{
    long int n;
    char nome[50], cognome[50];
    printf ("\n\nInserire nome:\t");
    scanf ("%s", nome);
    printf ("\n\nInserire cognome:\t");
    scanf ("%s", cognome);
    printf ("\n\nInserire numero di telefono:\t");
    scanf ("%li", &n);
    fprintf (new_rubrica, "%s\t%s\t%li", nome, cognome, n);
}

/*void mod()
{

}*/

void choose()
{
    char c;
    printf ("\n\nInserire 'm' per MODIFICARE un numero di telefono 'c' per CANCELLARE tutto e 'a' per AGGIUNGERE un contatto:\t");
    scanf ("%c", &c);
    switch (c)
    {
        //case 'm': mod(); break;
        case 'c': clean(); break;
        case 'a': add(); break;
        default: break;
    }
}

void copy(struct dati d[], size_t l)
{
    new_rubrica = fopen ("New_rubrica/new_rubrica.txt", "a");
    rubrica = fopen ("./rubrica.txt", "r+");
    int  i=0;
    char c;
    while (! feof(rubrica))
    {
        fscanf (rubrica, "%s\t%s\t%li", d[i].nome, d[i].cognome, &d[i++].numero);
        print(d, l);
    }
    printf ("\n%s 1\n", d[0].nome);
}

void close()
{
    fclose (rubrica);
    fclose (new_rubrica);
}

int main()
{
    int n_righe = countline();
    printf ("%d", n_righe);
    struct dati d[n_righe];

    control();
    new_dir();
    copy(d, n_righe);
    choose();
    close();

    return 0;
}