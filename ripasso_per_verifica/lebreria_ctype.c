#include<stdio.h>
#include<ctype.h>

void main()
{

int i,n;
char parola[10], ch;

printf ("\n\nInserire la parola:\t");
ch = getchar();

while (ch!='\n' && n<12)
{
    parola[n++] = ch;
    ch = getchar();
}

printf ("\n\nLa parola e':\t");
for (i=0;i<n;i++)
{
    if(islower(parola[i])==1)
    {
        parola[i] = toupper(parola[i]);
    }
    else if(isupper(parola[i])==1)
    {
        parola[i] = tolower(parola[i]);
    }
    putchar(parola[i]);
}



    return(0);
}