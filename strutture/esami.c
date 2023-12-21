#include<stdio.h>
#include<string.h>

struct esame
{
    char tipo[20];
    int voto;
};


void main()
{
int n;

printf ("\n\nInserire quanti esami hai dato:\t");
scanf ("%d", &n);

struct esame e[n];          

for (int i=0; i<n; i++)
{
    printf ("\n\nInseririre la materia del %d esame:\t", i+1);
    scanf ("%s", e[i].tipo);

    printf ("\nInserire il voto del %d esame:\t", i+1);
    scanf ("%d", &e[i].voto);
}
 
char trova[20];
int loc, ok=0;

printf ("\n\nInserire l'esame da trovare:\t");
scanf ("%s", trova);

for (int i=0; i<n; i++)
{
    if (strcmp(trova, e[i].tipo)==0) 
    {
        ok = 1;
        loc = i;
    }
}

if (ok == 1)
{
    printf ("\n\nNell'esame %s hai preso %d", e[loc].tipo, e[loc].voto);
}
else
{
    printf ("\n\nEsame non valido");
}

}