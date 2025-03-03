#include<stdio.h>
#include<string.h>
#include<ctype.h>

void convert(int l, char parola[l])
{
    for (int i = 0; i < l; i++)     //trovo e converto le vocali da minuscole a maiuscole
    {
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u')
        {
            parola[i] = toupper(parola[i]);
        }
    }

    printf ("\n\nLa parola convertita e':\t");
    for (int i = 0; i < l; i++)
    {
        printf ("%c", parola[i]);
    }
}

void main()
{

char parola[20];

printf ("\n\nInserire la parola:\t");
scanf ("%s", parola);

int l = strlen(parola);

convert(l, parola);

}