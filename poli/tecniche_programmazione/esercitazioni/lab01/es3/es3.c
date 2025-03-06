#include <stdio.h>

int main(void)
{
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;

    if ((fp_read = fopen("./bronte.txt", "r")) == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("./output_odd.txt", "w")) == NULL)
    {
        printf("Error opening file\n");
        return 2;
    }
    if ((fp_write_even = fopen("./output_even.txt", "w")) == NULL)
    {
        printf("Error opening file\n");
        return 3;
    }

    printf("What's your name?:\t");
    // gets(name);         // this not work
    fgets(name, 20, stdin); // use this instead

    while (!feof(fp_read))
    {
        counter++;
        if (counter % 2 == 0)
        {
            fscanf(fp_read, "%s", file_string);
            if (!feof(fp_read))
            {
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        }
        else
        {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read))
            {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }

    fclose(fp_read);
    fclose(fp_write_odd);
    fclose(fp_write_even);

    return 0;
}