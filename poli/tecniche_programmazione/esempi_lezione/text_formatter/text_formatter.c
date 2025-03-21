#include <stdio.h>
#include <string.h>

#define IN_FILE "./input.txt"
#define OUT_FILE "./output.txt"

int format_text(FILE *in, FILE *out, int m);

int main(void)
{
    FILE *in, *out;

    int margin_size;

    printf("\nSet margin size:\t");
    scanf("%d", &margin_size);

    in = fopen(IN_FILE, "r");
    out = fopen(OUT_FILE, "w");

    printf(format_text(in, out, margin_size) < 0 ? "\nSomething went wrong\n" : "\nText formatted correctly\n");

    fclose(in);
    fclose(out);

    return 0;
}

int format_text(FILE *in, FILE *out, int m)
{
    if (in == NULL || out == NULL)
        return -1;

    int position = 0;
    char word[20];
    while (fscanf(in, "%s", word) == 1)
    {
        if (position + strlen(word) + 1 > m)
        {
            position = 0;
            fputc('\n', out);
        }
        else if (position != 0)
            fputc(' ', out);

        fprintf(out, "%s", word);
        position += strlen(word) + 1;
    }
    return 0;
}