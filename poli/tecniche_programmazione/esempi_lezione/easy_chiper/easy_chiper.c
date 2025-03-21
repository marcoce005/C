#include <stdio.h>

#define INPUT_PATH "./clear.txt"
#define OUTPUT_PATH "./chiper.txt"

int crypt(FILE *in, FILE *out); // return -1 if there is an error

int main(void)
{
    FILE *clear, *chiper;

    clear = fopen(INPUT_PATH, "r");
    chiper = fopen(OUTPUT_PATH, "w");

    printf(crypt(clear, chiper) ? "\nSomething went wrong\n" : "File was crypted correctly");

    fclose(clear);
    fclose(chiper);

    return 0;
}

int crypt(FILE *in, FILE *out)
{
    if (in == NULL || out == NULL)
        return -1;

    char ch;
    while (fscanf(in, "%c", &ch) == 1)
    {
        // if (ch >= '0' && ch <= '9') // we can also use isnum()
        //     ch = '0' + ('9' - ch);
        // else if (ch >= 'A' && ch <= 'Z') // we can also use isupper()
        //     ch = 'a' + ('Z' - ch);
        // else if (ch >= 'a' && ch <= 'z') // we can also use islower()
        //     ch = 'A' + ('z' - ch);

        ch = ch >= '0' && ch <= '9' ? '0' + ('9' - ch) : ch >= 'A' && ch <= 'Z' ? 'a' + ('Z' - ch)
                                                     : ch >= 'a' && ch <= 'z'   ? 'A' + ('z' - ch)
                                                                                : ch;
        fputc(ch, out);
    }

    return 0;
}