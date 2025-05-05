#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXT_PATH "./testo.txt"
#define SEQUENCE_PATH "./sequenze.txt"
#define MAX_WORDS 1000
#define MAX_LEN_WORD 25 + 1

int read_text(FILE *in, char l[][MAX_LEN_WORD]);
int print_occurence(FILE *in, char text[][MAX_LEN_WORD], int l);
int str_in_text(char sub[], char str[]); // if the sub_string in str
void to_lower(char str[], char lower[]);
void clear_str(char s[], int l);

int main(void)
{
    FILE *fp_text, *fp_sequence;
    char text[MAX_WORDS][MAX_LEN_WORD];
    int len, ans;

    fp_text = fopen(TEXT_PATH, "r");
    len = read_text(fp_text, text);
    if (len < 0)
    {
        fclose(fp_text);
        return -1;
    }

    fp_sequence = fopen(SEQUENCE_PATH, "r");
    ans = print_occurence(fp_sequence, text, len);
    if (ans < 0)
    {
        fclose(fp_sequence);
        fclose(fp_text);
        return -1;
    }

    fclose(fp_text);
    fclose(fp_sequence);

    return 0;
}

int print_occurence(FILE *in, char text[][MAX_LEN_WORD], int l)
{
    if (in == NULL)
    {
        printf("\nFile Error.\nFile %s not found", SEQUENCE_PATH);
        return -1;
    }

    int end, i, j, count;
    char sub_str[MAX_LEN_WORD], lower[MAX_LEN_WORD] = "";

    if (fscanf(in, "%d", &end) != 1 || end <= 0)
    {
        printf("\nParameter Error.\n%s need for the first word the number of words that follow [must be greater than 0]", SEQUENCE_PATH);
        return -1;
    }

    for (i = 0; i < end; i++)
    {
        fscanf(in, "%s", sub_str);
        count = 0;

        printf("\nOccurence word '%s':\n", sub_str);
        for (j = 0; j < l && count < 10; j++)
        {
            clear_str(lower, sizeof(lower));
            to_lower(text[j], lower);

            if (str_in_text(sub_str, lower))
            {
                printf(" - '%s' (position %d)\n", text[j], j + 1);
                count++;
            }
        }
    }

    return 0;
}

void clear_str(char s[], int l)
{
    for (int i = 0; i < l; i++)
        s[i] = '\0';
}

void to_lower(char str[], char lower[])
{
    for (int i = 0; i < strlen(str); i++)
        lower[i] = tolower(str[i]);
}

int str_in_text(char sub[], char str[])
{
    if (strlen(sub) > strlen(str))
        return 0;

    int i, j;
    for (i = 0; i <= strlen(str) - strlen(sub); i++)
    {
        for (j = 0; j < strlen(sub) && str[i + j] == sub[j]; j++)
            ;
        if (j == strlen(sub))
            return 1;
    }
    return 0;
}

int read_text(FILE *in, char l[][MAX_LEN_WORD])
{
    if (in == NULL)
    {
        printf("\nFile Error.\nFile %s not found", TEXT_PATH);
        return -1;
    }

    int i;
    for (i = 0; i < MAX_WORDS && fscanf(in, "%s", l[i]) == 1; i++)
        ;
    return i;
}