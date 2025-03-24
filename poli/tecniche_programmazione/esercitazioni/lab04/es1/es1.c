#include <stdio.h>
#include <ctype.h>
#include <string.h>

// return -1 in case of error || return the number of charaters written in the output file
int compress(FILE *in, FILE *out);
int decompress(FILE *in, FILE *out);

int main(void)
{
    char mod, file_in[20], file_out[20];
    FILE *in_file, *out_file;
    int ans;

    printf("\n[c] to compress the text\n[d] to decompress the text\n-->");
    scanf("%c", &mod);

    printf("\nSelect the input file [write the path (ex. './ciro_in.txt')]:\t");
    scanf("%s", file_in);

    printf("\nSelect the name of the output file [write the path (ex. './ciro_out.txt')]:\t");
    scanf("%s", file_out);

    in_file = fopen(file_in, "r");
    out_file = fopen(file_out, "w");

    switch (tolower(mod))
    {
    case 'c':
        ans = compress(in_file, out_file);
        break;

    case 'd':
        ans = decompress(in_file, out_file);
        break;

    default:
        printf("\nWrong settings!!!");
        break;
    }

    if (ans < 0)
        printf("\nSomething went wrong\nPlease check file's path.\n");
    else
        printf("\n%d character was been written in the %s file\n", ans, file_out);

    fclose(in_file);
    fclose(out_file);

    return 0;
}

int compress(FILE *in, FILE *out)
{
    if (in == NULL || out == NULL)
        return -1;

    int char_count = 0, occurence = 1;
    char prev = fgetc(in), curr, str_number[10];

    while (fscanf(in, "%c", &curr) == 1)
    {
        while (prev == curr && occurence < 10)
        {
            occurence++;
            curr = fgetc(in);
        }

        if (occurence > 2)
        {
            fprintf(out, "%c$%d", prev, occurence - 1);
            sprintf(str_number, "%d", occurence - 1);
            char_count += 2 + strlen(str_number);
        }
        else if (occurence == 2)
        {
            fprintf(out, "%c%c", prev, prev);
            char_count += 2;
        }
        else
        {
            fputc(prev, out);
            char_count++;
        }
        occurence = 1;
        prev = curr;
    }
    return char_count;
}

int decompress(FILE *in, FILE *out)
{
    if (in == NULL || out == NULL)
        return -1;

    char curr, prev = fgetc(in), times;
    int char_count = 0;

    while (fscanf(in, "%c", &curr) == 1)
    {
        if (curr == '$')
        {
            fscanf(in, "%c", &times);

            for (int i = 0; i < (times - '0'); i++)
            {
                fputc(prev, out);
                char_count++;
            }
        }
        else if (char_count == 0)
        {
            fprintf(out, "%c%c", prev, curr);
            char_count += 2;
        }
        else
        {
            putc(curr, out);
            char_count++;
        }
        prev = curr;
    }
    return char_count;
}