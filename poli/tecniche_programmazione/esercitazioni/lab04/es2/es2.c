#include <stdio.h>
#include <ctype.h>

// return -1 in case of error || return the number of charaters written in the output file
int crypt(FILE *in, FILE *out);
int decrypt(FILE *in, FILE *out);

int main(void)
{
    int ans;
    char mod, file_in[20], file_out[20];
    FILE *in_file, *out_file;

    printf("\n[c] to crypt the text\n[d] to de-crypt the text\n-->");
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
        ans = crypt(in_file, out_file);
        break;

    case 'd':
        ans = decrypt(in_file, out_file);
        break;

    default:
        printf("\nWrong settings!!!");
        break;
    }

    if (ans < 0)
        printf("\nSomething went wrong\nPlease check file's path.\n");
    else
        printf("\n%d character was been written in the %s file\n", ans, file_out);

    return 0;
}

int crypt(FILE *in, FILE *out)
{
    if (in == NULL || out == NULL)
        return -1;

    int k = 0, written_char = 1, h;
    char prev = fgetc(in), curr;

    fputc(prev, out); // first character is always the same
    if (isdigit(prev))
        k++;

    while (fscanf(in, "%c", &curr) == 1)
    {
        if (isdigit(curr))
        {
            curr = '0' + (curr - '0' + k) % 10;
            k++;
        }
        else if (isalpha(curr) && !isalpha(prev))
            k = 0;
        else if (isalpha(curr) && isalpha(prev))
        {
            h = isupper(prev) ? prev - 'A' : prev - 'a';
            curr = isupper(curr) ? 'A' + (curr - 'A' + h) % 26 : 'a' + (curr - 'a' + h) % 26;
        }
        
        fputc(curr, out);
        written_char++;
        prev = curr;
    }
    return written_char;
}

int decrypt(FILE *in, FILE *out)
{
    if (in == NULL || out == NULL)
        return -1;

    int k = 0, written_char = 1, h;
    char prev = fgetc(in), curr;

    fputc(prev, out); // first character is always the same
    if (isdigit(prev))
        k++;

    while (fscanf(in, "%c", &curr) == 1)
    {
        if (isdigit(curr))
        {
            fputc('0' + (10 + curr - '0' - k) % 10, out);
            k++;
        }
        else if (isalpha(curr) && !isalpha(prev))
        {
            k = 0;
            fputc(curr, out);
        }
        else if (isalpha(curr) && isalpha(prev))
        {
            h = isupper(prev) ? prev - 'A' : prev - 'a';

            if (isupper(curr))
                fputc('A' + ((26 + curr - 'A' - h) % 26), out);
            else
                fputc('a' + ((26 + curr - 'a' - h) % 26), out);
        }
        else
            fputc(curr, out);
        written_char++;
        prev = curr;
    }
    return written_char;
}