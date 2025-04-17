#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN_STR 50

int check_palindrome(char s[], int len);

int main(void)
{
    char str[MAX_LEN_STR];

    printf("\nInsert a palindrome word:\t");
    fgets(str, MAX_LEN_STR, stdin);

    printf("\n%s", check_palindrome(str, strlen(str)) ? "palindrome" : "not palindrome");

    return 0;
}

int check_palindrome(char s[], int len)
{
    for (int j = 0, i = len - 2; j < len / 2; j++, i--) // len - 2 --> because index start from 0 and when you type you add also a final '\n'
        if (tolower(s[i]) != tolower(s[j]))
            return 0;
    return 1;
}