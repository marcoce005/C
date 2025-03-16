#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "./input.txt"
#define LEN_NUMBER 5
#define TEMP1 "T1:"
#define TEMP2 "T2:"

void read_data_from_file(int *tot1, int *tot2, int *count1, int *count2);

int main(void)
{
    int tot_T1 = 0, tot_T2 = 0, count_T1 = 0, count_T2 = 0;

    read_data_from_file(&tot_T1, &tot_T2, &count_T1, &count_T2);

    printf("\nAverage T1:\t%.1f\nAverage T2:\t%.1f\n", (float)tot_T1 / count_T1, (float)tot_T2 / count_T2);

    return 0;
}

void read_data_from_file(int *tot1, int *tot2, int *count1, int *count2)
{
    FILE *file;
    file = fopen(FILE_PATH, "r");

    int which_temp = 0;

    char str[LEN_NUMBER];

    while (!feof(file))
        if (!feof(file))
        {
            fscanf(file, "%s", str);

            if (strcmp(str, TEMP1) == 0)
                which_temp = 1;
            if (strcmp(str, TEMP2) == 0)
                which_temp = 2;

            if (atoi(str) != 0)
            {
                if (which_temp == 1)
                {
                    *tot1 += atoi(str);
                    (*count1)++;
                }
                else if (which_temp == 2)
                {
                    *tot2 += atoi(str);
                    (*count2)++;
                }
            }
        }
}