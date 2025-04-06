#include <stdio.h>

#define ARR_LEN 256
#define DIC "./ascii_rot7.txt"
#define PLAIN "./plain_text.txt"
#define CHIPER "./chiper_text.txt"
#define OUTPUT "./output.txt"

int get_dict(FILE *in, char d[]);
int crypt(FILE *in, FILE *out, char d[]);
int decrypt(FILE *in, FILE *out, char d[]);

int main(void)
{
    FILE *in, *out, *f_dict;

    char dict[ARR_LEN];

    f_dict = fopen(DIC, "r");

    if (get_dict(f_dict, dict) < 0)
    {
        printf("\nError!!!\n");
        fclose(f_dict);
        return -1;
    }

    // in = fopen(PLAIN, "r");
    // out = fopen(CHIPER, "w");

    // if (crypt(in, out, dict) < 0)
    // {
    //     printf("\nError!!!\n");
    //     fclose(f_dict);
    //     fclose(in);
    //     fclose(out);
    //     return -1;
    // }
    // else
    //     printf("\n%s was been crypted in %s", PLAIN, CHIPER);

    in = fopen(CHIPER, "r");
    out = fopen(OUTPUT, "w");

    if (decrypt(in, out, dict) < 0)
    {
        printf("\nError!!!\n");
        fclose(f_dict);
        fclose(in);
        fclose(out);
        return -1;
    }
    else
        printf("\n%s was been decrypted in %s", CHIPER, OUTPUT);

    fclose(f_dict);
    fclose(in);
    fclose(out);

    return 0;
}

int decrypt(FILE *in, FILE *out, char d[])
{
    if (in == NULL || out == NULL)
        return -1;

    char d_reverse[ARR_LEN];
    for (int i = 0; i < ARR_LEN; i++)
        d_reverse[(int)d[i]] = (char)i;

    crypt(in, out, d_reverse);

    return 0;
}

int crypt(FILE *in, FILE *out, char d[])
{
    if (in == NULL || out == NULL)
        return -1;

    char ch;
    while (fscanf(in, "%c", &ch) == 1)
        fputc(d[(int)ch], out);

    return 0;
}

int get_dict(FILE *in, char d[])
{
    if (in == NULL)
        return -1;

    int index, ch;
    while (fscanf(in, "%d %d", &index, &ch) == 2)
        d[index] = (char)ch;
    return 0;
}