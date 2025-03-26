#include <stdio.h>
#include <ctype.h>

#define FILE_IN "./input.txt"
#define FILE_OUT "./output.txt"

// it return -1 in case of error
int elaborate_text(FILE *in, FILE *out);

int main(void)
{
    FILE *in, *out;
    int ans;

    in = fopen(FILE_IN, "r");
    out = fopen(FILE_OUT, "w");

    ans = elaborate_text(in, out);

    if (ans < 0)
        printf("\nSomething went wrong\nPlease check file's path.\n");
    else
        printf("\nText was been written in the %s file\n", FILE_OUT);

    return 0;
}

int elaborate_text(FILE *in, FILE *out)
{
    if (in == NULL || out == NULL)
        return -1;

    int count = 0, capitalize = 0;
    char curr, prev = fgetc(in);

    while (fscanf(in, "%c", &curr) == 1)
    {
        if (count == 25 || prev == '\n')
        {
            if (prev == '\n')
            {
                for (int i = count; i < 25; i++)
                    fputc(' ', out);
                fprintf(out, "| c:%d\n", count);
                count = 0;
            }
            else
            {
                fprintf(out, "| c:25\n%c", prev);
                count = 1;
            }
        }
        else
        {
            if (isdigit(prev))
            {
                fputc('*', out);
            }
            else
                switch (prev)
                {
                case '.':
                case ',':
                case ';':
                case ':':
                case '?':
                case '!':
                case '\'':
                    if (curr != ' ' && curr != '\n')
                    {
                        fprintf(out, "%c ", prev);
                        count++;
                    }
                    else
                    {
                        fputc(prev, out);
                    }

                    if (prev == '?' || prev == '!' || prev == '.')
                        capitalize = 1;
                    break;

                default:
                    if (isalpha(prev) && capitalize)
                    {
                        fputc(toupper(prev), out);
                        capitalize = 0;
                    }
                    else
                        fputc(prev, out);
                    break;
                }
            count++;
        }
        prev = curr;
    }

    fputc(prev, out);
    count++;
    for (int i = count; i < 25; i++)
        fputc(' ', out);
    fprintf(out, "| c:%d", count);

    return 0;
}