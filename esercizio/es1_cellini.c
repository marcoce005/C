#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int n_gg;

struct Data
{   
    int gg;
    int m;
    int a;
}d;

void NextData(int bisestile)
{
    d.gg += 7;
    if (d.m == 1 || d.m == 3 || d.m == 5 || d.m == 7 || d.m == 8 || d.m == 10 || d.m == 12)
        if (d.gg > 31)
        {
            d.gg -= 31;
            d.m++;
        }
    if (d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11)
        if (d.gg > 30)
        {
            d.gg -= 30;
            d.m++;
        }
    if (d.m == 2)
        if (d.gg > bisestile)
        {
            d.gg -= bisestile;
            d.m++;
        }
}

void calcolagg(char gg_lettere[])
{
    int r;
    if (strcmp(gg_lettere, "lunedi") == 0)
        r=5;
    else if (strcmp(gg_lettere, "martedi") == 0)
        r=4;
    else if (strcmp(gg_lettere, "mercoledi") == 0)
        r=3; 
    else if (strcmp(gg_lettere, "giovedi") == 0)
        r=2;
    else if (strcmp(gg_lettere, "venerdi") == 0)
        r=1;
    else if (strcmp(gg_lettere, "sabato") == 0)
        r=0;
    else if (strcmp(gg_lettere, "domenica") == 0)
        r=6;
    d.gg = r +1;
}

int main()
{
    char gg_lettere[20];
    int bisestile;
    d.m = 1;

    printf ("\n\nInserire l'anno:\t");
    scanf_s ("%d", &d.a);
    printf ("\n\nChe giono e' il primo giorno del %d (scrivilo minuscolo senza accenti):\t", d.a);
    scanf_s ("%s", gg_lettere);
    calcolagg(gg_lettere);
    
    if (d.a % 4 == 0 && d.a % 100 != 0 || d.a % 400 == 0)
            bisestile = 29;
        else
            bisestile = 28;

    printf ("\n\n%d/%d/%d  ", d.gg, d.m, d.a);
    for (int i = 0; i < 52; i++)
    {    
        NextData(bisestile);
        if (d.m == 13)
            exit(1);
        printf ("%d/%d/%d ", d.gg, d.m, d.a);
        if (i != 0 && i % 10 == 0)
            printf ("\n");
        
    }
}