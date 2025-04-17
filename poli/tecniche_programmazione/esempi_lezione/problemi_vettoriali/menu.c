#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 50
#define KEYWORD 4
#define MAX_KEY_LEN 9

void to_lower(char str[], int l);
int selector(char str[], char key[KEYWORD][MAX_KEY_LEN]);

int main(void)
{
    int n, exit = 0;
    char key_word[KEYWORD][MAX_KEY_LEN] = {"fine", "cerca", "modifica", "stampa"}, str[MAX_STR_LEN], word[MAX_KEY_LEN];

    to_lower(str, sizeof(str));

    while (exit == 0)
    {
        printf("\nInsert string with selector:\t");
        fgets(str, MAX_STR_LEN, stdin);
        sscanf(str, "%s", word);

        switch (selector(word, key_word))
        {
        case 0:
            printf("\nThe END");
            exit = 1;
            break;

        case 1:
            printf("\nSearch");
            // search();
            break;

        case 2:
            printf("\nEdit");
            // edit();
            break;

        case 3:
            printf("\nPrint");
            // print();
            break;
        default:
            printf("\nError");
            break;
        }
    }

    return 0;
}

int selector(char str[], char key[KEYWORD][MAX_KEY_LEN])
{
    for (int i = 0; i < KEYWORD; i++)
        if (strcmp(str, key[i]) == 0)
            return i;
    return -1;
}

void to_lower(char str[], int l)
{
    for (int i = 0; i < l; i++)
        str[i] = tolower(str[i]);
}