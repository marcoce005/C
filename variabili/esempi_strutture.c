#include<stdio.h>
#include<string.h>

struct alunno       //la struttura raccoglie una serie di variabili
{
    char cognome[30];
    char nome[30];
    char sezione[10];
    int classe[1];
} s2;

void main()
{

struct alunno a1 = {"Cellini","Marco","I",3};   //assegnazione dei valori alle variabili della struttura

printf ("\nInserire Cognome:\t");
gets(s2.cognome);                           //riempimento della struttura dall'utente 
printf ("\nInserire Nome:\t");
gets(s2.nome);
printf ("\nInserire Sezione:\t");
gets(s2.sezione);
printf ("\nInserire Classe:\t");
gets(s2.classe);

printf ("\n\nNome =\t%s\n",a1.nome);
printf ("Cognome =\t%s\n",a1.cognome);
printf ("Sezione =\t%s\n",a1.sezione);      //stampa della riga 14
printf ("Classe =\t%d\n",a1.classe[0]);

printf ("\n\nNome =\t%s\n",s2.nome);
printf ("Cognome =\t%s\n",s2.cognome);      //stampa del gets
printf ("Sezione =\t%s\n",s2.sezione);
printf ("Classe =\t%d\n",s2.classe[0]);




    return(0);
}