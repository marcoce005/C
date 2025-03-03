#include<stdio.h>
#include<string.h>
#include<ctype.h>

int cont_voc(int l, char parola[l])
{
    int cont;
    for (int i = 0; i < l; i++)
    {
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u')
        {
            for (int k = i; k < l; k++)         //trova la prima vocale 
            {
                if (parola [i] == parola[k])        // conto quante volte compare
                {
                    cont++;
                }
            }
            break;
        }
    }
    return(cont);
}

void main()
{

char parola[20];

printf ("\n\nInserire la parola:\t");
scanf ("%s", parola);

int l = strlen(parola);

for (int i = 0; i < l; i++)     //converto tutto in minuscolo per non avere problemi dopo
{
    parola[i] = tolower(parola[i]);
}

int conta = cont_voc(l, parola);

printf ("\n\nLa prima vocale e' ripetuta %d volte", conta);

}