#include<stdio.h>

struct alunno
{
    char nome[20];
    char cognome[20];
    int classe;
    char sezione[20];
}a1,a2;

void main()
{

struct alunno a1 = {"Giusto!!!", "Linux", 3, "Pinguini"};

printf ("\nL'alunno e':\t%s\t%s\t%d\t%s",a1.nome, a1.cognome, a1.classe, a1.sezione);




















    return(0);
}