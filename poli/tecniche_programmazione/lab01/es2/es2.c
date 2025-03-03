#include <stdio.h>

int main(void)
{
    FILE *fp_read, *fp_write;
    char file_char, choice;

    if ((fp_read = fopen("./guide.txt", "r")) == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write = fopen("./output.txt", "w")) == NULL)
    {
        printf("Error opening file\n");
        return 2;
    }

    printf("Print on console (C) or on file (F):\t");
    choice = getchar();

    while (!feof(fp_read))
    {
        file_char = fgetc(fp_read);
        if (!feof(fp_read)) // if I omit this line it will print also the end-of-file character '\0'
        {
            switch (choice)
            {
            case 'C':
                printf("\nChar printed on the console:\t%c", file_char);
                break;

            case 'F':
                printf("\nChar saved on file:\t");
                putchar(file_char);
                // fputc(file_char, fp_write);      //print in file
                break;

            default:
                printf("Wrong choice\n");
                return 3;
            }
        }
    }

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}