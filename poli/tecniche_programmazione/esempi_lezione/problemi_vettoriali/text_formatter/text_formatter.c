#include <stdio.h>
#include <string.h>

#define MAX_LEN_WORD 20
#define IN_PATH "./input.txt"
#define OUT_PATH "./output.txt"

int formatter(FILE *in, FILE *out, int lmax);

int main(void)
{
    int result, margin;

    FILE *in, *out;

    in = fopen(IN_PATH, "r");
    out = fopen(OUT_PATH, "w");

    printf("\nEnter the margin: ");
    scanf("%d", &margin);

    result = formatter(in, out, margin);

    if (result < 0)
    {
        printf("\nError: check margin or file path.\n");
        return -1;
    }

    fclose(in);
    fclose(out);

    return 0;
}

int formatter(FILE *in, FILE *out, int lmax)
{
    if (in == NULL || out == NULL || lmax <= 0)
        return -1;

    char line[256], word[MAX_LEN_WORD];
    int len = -1;

    line[0] = '\0';

    while (fscanf(in, "%s", word) == 1)
    {
        if (strlen(word) + len + 1 <= lmax)
        {
            if (len > 0)
                strcat(line, " ");
            strcat(line, word);
            len += strlen(word) + 1;
        }
        else
        {
            for (int i = 0; i < (lmax - len) / 2; i++)
                fprintf(out, " ");
            fprintf(out, "%s\n", line);
            strcpy(line, word);
            len = strlen(word);
        }
    }
    
    for (int i = 0; i < (lmax - len) / 2; i++)
        fprintf(out, " ");
    fprintf(out, "%s", line);

    return 0;
}