#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{

int i,l=0,vocale=0,consonante=0;
char parola[50];

printf ("\nInsrire la parola:\t");
fgets (parola, sizeof(parola), stdin);

l=(strlen (parola)-1);

for (i=0;i<l;i++)
{
    if (parola[i]=='\0')
    {}
    else
    {
        if (parola[i]==' ')
        {}
       else if (parola[i]=='a'||parola[i]=='A' || parola[i]=='e' || parola[i]=='E' || parola[i]=='i' || parola[i]=='I' || parola[i]=='o' || parola[i]=='O' || parola[i]=='u' || parola[i]=='U')
        {
            vocale++;
        }
        else if (isupper(parola[i])==0)
        {
            consonante++;
        } 
    }
    
}

printf ("\n\nLe vocali sono:\t%d\nLe consonantii sono:\t%d\n",vocale,consonante);

    sleep (5);
    return(0);
}