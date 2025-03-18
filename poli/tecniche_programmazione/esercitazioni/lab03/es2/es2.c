#include <stdio.h>

int is_leap(int y);                  // 1 if is leap
int check_date(int d, int m, int y); // 1 if it's a wrong date
int days_in_month(int m, int y);     // return the numbers of days in a specific month
void next_N_day(int *d, int *m, int *y, int n);

int main(void)
{
    char str[11];
    int d, m, y, n;

    printf("\nInsert date [gg/mm/aaaa]:\t");
    scanf("%s", str);

    sscanf(str, "%d/%d/%d", &d, &m, &y);

    if (check_date(d, m, y))
    {
        printf("\nWrong date!!!");
        return -1;
    }

    printf("\nInsert N number:\t");
    scanf("%d", &n);

    next_N_day(&d, &m, &y, n);

    printf("\n%d/%d/%d", d, m, y);

    return 0;
}

int is_leap(int y) { return (y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 4 == 0); }

int check_date(int d, int m, int y) { return !(d > 0 && d < 32 && m > 0 && m < 13 && y > 0 && y < 2026); }

int days_in_month(int m, int y)
{
    if (m != 2)
        switch (m)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;

        default:
            return 31;
            break;
        }
    else
        return is_leap(y) ? 29 : 28;
    return -1; // in case of error;
}

void next_N_day(int *d, int *m, int *y, int n)
{
    // int feb = is_leap((*y)) ? 29 : 28, days;

    // switch (*m)
    // {
    // case 4:
    // case 6:
    // case 9:
    // case 11:
    //     days = 30;
    //     break;

    // default:
    //     days = 31;
    //     break;
    // }

    while (n != 0)
    {
        /* code */
    }
}