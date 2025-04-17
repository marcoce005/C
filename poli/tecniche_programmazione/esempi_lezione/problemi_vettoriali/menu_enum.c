#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    c_cerca,
    c_modifica,
    c_stampa,
    c_fine,
    c_err
} t_comandi;

#define MAX_STR_LEN 50
#define KEYWORD 4
#define MAX_KEY_LEN 9

void to_lower(char str[], int l);
t_comandi selector(char str[], char key[KEYWORD][MAX_KEY_LEN]);

int main(void)
{
    int n, exit = 0;
    char key_word[KEYWORD][MAX_KEY_LEN] = {"cerca", "modifica", "stampa", "fine"}, str[MAX_STR_LEN], word[MAX_KEY_LEN];

    to_lower(str, sizeof(str));

    while (exit == 0)
    {
        printf("\nInsert string with selector:\t");
        fgets(str, MAX_STR_LEN, stdin);
        sscanf(str, "%s", word);

        switch (selector(word, key_word))
        {
        case c_fine:
            printf("\nThe END");
            exit = 1;
            break;

        case c_cerca:
            printf("\nSearch");
            // search();
            break;

        case c_modifica:
            printf("\nEdit");
            // edit();
            break;

        case c_stampa:
            printf("\nPrint");
            // print();
            break;
        case c_err:
            printf("\nError");
            break;
        }
    }

    return 0;
}

t_comandi selector(char str[], char key[KEYWORD][MAX_KEY_LEN])
{
    int i;
    for (i = 0; i < KEYWORD; i++)
        if (strcmp(str, key[i]) == 0)
            return i;
    return i;
}

void to_lower(char str[], int l)
{
    for (int i = 0; i < l; i++)
        str[i] = tolower(str[i]);
}