#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

double entropia(int n_lettere, int frequenza[n_lettere], float Pi[n_lettere])
{
    double H=0;                             // calcolo l'entropia della parola inserita
    for (int i = 1; i <= n_lettere; i++)
    {
        H += (-1) * (Pi[i-1] * log2(Pi[i-1]));
    }
    return(H);
}

void main()
{

char parola[20];

printf ("\n\nInserire la parola (non si accettano caratteri speciali):\t");       // il programma funziona sono con lettere dell'alfabeto (maiuscolo o minuscolo è indeferrente)
scanf ("%s", parola);

int i, y, k=0, l = strlen(parola);
int lettere[26] = {0}, cont_let=0;

for (i=0;i<l;i++)       // converto tutto in minuscolo
{
    parola[i] = tolower(parola[i]);
}

for (i=0; i<26; i++)
{
    for (y=0; parola[y] != 0; y++)
    {
        if (parola[y] == i+97)
        {
            lettere[i]++;
        }
    }
}

for (i=0; i<26; i++)
{
    if (lettere[i] != 0)
    {
        cont_let++;
    }
}
float Pi[cont_let]; 
int frequenza[cont_let];

for (i=0; i<26; i++)
{
    if (lettere[i] != 0)
    {
        frequenza[k] = lettere[i];
        Pi[k] = (float)frequenza[k] / (float)l;
        k++;
    }
}

double H = entropia(cont_let, frequenza, Pi);

printf ("\n\nH (%s) = %lf bit/sym", parola, H);


}