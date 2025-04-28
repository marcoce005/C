#include <stdio.h>
#include <string.h>

#define DICT_PATH "./dizionario.txt"
#define SOURCE_PATH "./sorgente.txt"
#define ENCODED_PATH "./ricodificato.txt"
// #define MAX_LEN 200
#define MAX_S 30

typedef struct Cell
{
    char encoded[MAX_S + 1];
    char original[MAX_S + 1];
} cell;

int create_dict(FILE *in, cell d[], int *s);
int word_in_str(char word[], char str[]); // return index of the substring in the string or -1 if the substing is not in the string
int encode_source(FILE *in, FILE *out, cell dict[], int s);

int main(void)
{
    FILE *fp_dict, *fp_source, *fp_encoded;
    cell dict[MAX_S];
    int S, ans;

    fp_dict = fopen(DICT_PATH, "r");

    ans = create_dict(fp_dict, dict, &S);

    if (ans < 0)
    {
        fclose(fp_dict);
        return -1;
    }

    fp_source = fopen(SOURCE_PATH, "r");
    fp_encoded = fopen(ENCODED_PATH, "w");

    ans = encode_source(fp_source, fp_encoded, dict, S);

    if (ans < 0)
    {
        fclose(fp_dict);
        fclose(fp_source);
        fclose(fp_encoded);
        return -1;
    }

    fclose(fp_dict);
    fclose(fp_source);
    fclose(fp_encoded);

    return 0;
}

int encode_source(FILE *in, FILE *out, cell dict[], int s)
{
    if (in == NULL || out == NULL)
    {
        printf("\nFile Error\nCheck files %s and %s", SOURCE_PATH, ENCODED_PATH);
        return -1;
    }

    int i, j, index;
    char word[MAX_S], ch = '\0';
    while (fscanf(in, "%s", word) == 1)
    {

        if (ch == '\n' || ch == ' ')
            fputc(ch, out);

        for (i = 0, index = -1; index == -1 && i < s; i++)
            index = word_in_str(dict[i].original, word);

        if (index != -1)
        {
            for (j = 0; j < index; j++)
                fputc(word[j], out);
            fputs(dict[i - 1].encoded, out);
        }
        else
            fputs(word, out);

        ch = fgetc(in);
    }
    return 0;
}

int word_in_str(char word[], char str[])
{
    if (strlen(word) > strlen(str))
        return -1;

    int i, j;
    for (i = 0; i <= strlen(str) - strlen(word); i++)
    {
        for (j = 0; j < strlen(word) && word[j] == str[i + j]; j++)
            ;
        if (j == strlen(word))
            return i;
    }
    return -1;
}

int create_dict(FILE *in, cell d[], int *s)
{
    if (in == NULL)
    {
        printf("\nFile Error\nFile %s not found", DICT_PATH);
        return -1;
    }

    fscanf(in, "%d", &(*s));

    if (*s > MAX_S)
    {
        printf("\nParam Error\nS value have to be <= %d", MAX_S);
        return -1;
    }

    for (int i = 0; i < (*s); i++)
        fscanf(in, "%s %s", d[i].encoded, d[i].original);
    return 0;
}