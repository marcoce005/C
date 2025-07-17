#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int myAtoi(char *s)
{
    int sgn = 1, i, tot = 0, start = 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            if (((s[i] - '0') + (double)tot * 10) * sgn >= pow(2, 31) - 1 ||
                ((s[i] - '0') + (double)tot * 10) * sgn <= -pow(2, 31))
            {
                return sgn == -1 ? -(int)pow(2, 31) - 1 : (int)(pow(2, 31) - 1);
            }
            tot = (s[i] - '0') + tot * 10;
            start = 1;
        }
        else if ((s[i] == '-' || s[i] == '+') && start == 0)
        {
            if (s[i] == '-')
                sgn = -1;
            start = 1;
        }
        else if (s[i] == ' ' && start == 0)
            continue;
        else
            return tot * sgn;
    }
    return tot * sgn;
}

int main(void)
{
    int i;
    char list[][20] = {
        "42",            //  -->     42
        "   -042",       //  -->     -42
        "1337c0d3",      //  -->     1337
        "0-1",           //  -->     0
        "words and 987", //  -->     0
        "-91283472332",  //  -->     2147483647
        "+1",            //  -->     1
        "-2147483648"    //  -->     2147483647
    };

    for (i = 0; i < sizeof(list) / sizeof(list[0]); i++)
        printf("\"%s\" --> %d\n", list[i], myAtoi(list[i]));

    return 0;
}