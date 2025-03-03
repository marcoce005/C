#include<stdio.h>
#include<ctype.h>
#include<string.h>

void n_vocali(int l, char parola[l])
{
    int cont=0;
    for (int i = 0; i < l; i++)
    {
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u')
        {
            parola[i] = toupper(parola[i]);
            cont++;
        }
    }
    printf ("\n\nLe vocali sono %d mentre le consonati sono %d.\nLa parola modificata e':%s", cont, l-cont, parola);
}

void main()
{

char parola[20];

printf ("\n\nInserire la parola:\t");
scanf ("%s", parola);

int l = strlen(parola);

for (int i = 0; i < l; i++)
{
    parola[i] = tolower(parola[i]);  
}

n_vocali(l, parola);

}