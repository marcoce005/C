#include<stdio.h>
#include<string.h>

void pari(int l, int totale, char *n)
{
    printf ("\n\nIl bit di parita' pari per la parola ");
    for (int i = 1; i < l; i++)
    {
        printf ("%d", n[i]-48);
    }
    printf (" e' %d", totale%2);
}

void dispari(int l, int totale, char *n)
{
    printf ("\n\nIl bit di parita' dispari per la parola ");
    for (int i = 1; i < l; i++)
    {
        printf ("%d", n[i]-48);
    }
    printf (" e' %d", !(totale%2));
}

int controllo(char n[20])
{
    int no=0;
    if (n[0] != 'P' && n[0] != 'D' || n[1] == '\0')
    {
        printf ("\n\nInserimento errato, necessario specificare il tipo di parita' (P|D); (perfavore non mettere spazi tra la lettera e il numero).");
        no++;
    }
    return(no);
}

int tot(int l, char *n)
{
    int tot=0;
    for (int i = 1; i < l; i++)
    {
        tot += n[i]-48;
    }
    return(tot);
}

void main(int argc, char *argv[])
{

char *n = argv[1];

int ok = controllo(n);

if (ok != 1)
{
    int l = strlen(n);
    int totale = tot(l, n);
    n[0] == 'P' ? pari(l, totale, n) : dispari(l, totale, n);
}

}