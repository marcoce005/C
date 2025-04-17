#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TABLE_PATH "./table.txt"
#define N_MONTH 12

typedef struct Month
{
    char id[36 + 1];
    char name[11];
} month;

int get_table(FILE *in, month m[], int len);
void to_lower(char str[], int l);
int id_month(month m[], char str[], int l, char ans[]);

int main(void)
{
    FILE *in;
    month months[N_MONTH];
    char str[20], id[36 + 1];
    int l, ans;

    in = fopen(TABLE_PATH, "r");

    l = get_table(in, months, N_MONTH);
    if (l < 0)
    {
        printf("\nFile Error");
        fclose(in);
        return -1;
    }

    printf("\nInsert a month:\t");
    scanf("%s", str);

    ans = id_month(months, str, l, id);

    if (ans < 0)
    {
        printf("\n%s is not a month.", str);
        return -1;
    }

    printf("\n%s --> %s", str, id);

    fclose(in);
    return 0;
}

int id_month(month m[], char str[], int l, char ans[])
{
    char s[20];
    strcpy(s, str);
    to_lower(s, sizeof(s));

    for (int i = 0; i < l; i++)
        if (strcmp(s, m[i].name) == 0)
        {
            strcpy(ans, m[i].id);
            return 0;
        }
    return -1;
}

int get_table(FILE *in, month m[], int len)
{
    if (in == NULL)
        return -1;

    int i = 0;
    while (i < len && fscanf(in, "%s %s", m[i].name, m[i].id) == 2)
        i++;

    return i;
}

void to_lower(char str[], int l)
{
    for (int i = 0; i < l; i++)
        str[i] = tolower(str[i]);
}