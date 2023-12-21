#include<stdio.h>
#include<ctype.h>
#include<string.h>

void modifica(char str_in[], int lung)
{
    char voc[50], altre[50];
    int j=0, k=0;
    
    for (int i = 0; i < lung; i++)
    {
        if (isalpha(str_in[i]))
        {
            if (tolower(str_in[i]) == 'a' || tolower(str_in[i]) == 'e' || tolower(str_in[i]) == 'i' || tolower(str_in[i]) == 'o' || tolower(str_in[i]) == 'u')
                voc[j++] = str_in[i];
            else
                altre[k++] = str_in[i];
        }
        else
            altre[k++] = str_in[i];
    }

    fflush(stdin);

    printf ("\n\nStringa modificata:\t");
    for (int i = 0; i < strlen(voc); i++)
        printf ("%c", voc[i]);
    fflush(stdin);
    for (int i = 0; i < strlen(altre); i++)
        printf ("%c", altre[i]);
}

int main()
{
    char str_in[50];

    printf ("\n\nInserire la stringha:\t");
    fgets (str_in, 50, stdin);

    fflush(stdin);

    int l = strlen(str_in);

    modifica(str_in, l);

    return 0;
}