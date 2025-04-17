#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_lower(char str[], int len);
int find_month(char months[][20], int len, char val[]);

int main(void)
{
    char months[12][20] = {
        "january", "february",
        "march", "april",
        "may", "june",
        "july", "august",
        "september", "october",
        "november", "december"};

    char month[20];
    printf("\nDigit a month:\t");
    scanf("%s", month);

    int ans = find_month(months, sizeof(months) / sizeof(months[0]), month);
    if (ans < 0)
        printf("\nThis month '%s' does not exist.\n", month);
    else
        printf("\n%s --> %d\n", month, ans);

    return 0;
}

int find_month(char months[][20], int len, char val[])
{
    int i;
    for (i = 0; i < len; i++)
        if (strcmp(months[i], val) == 0)
            return i + 1;
    return -1;
}

void to_lower(char str[], int len)
{
    for (int i = 0; i < len; i++)
        str[i] = tolower(str[i]);
}