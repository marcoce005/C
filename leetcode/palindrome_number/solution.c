#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(void)
{
    int i, test[] = {
               121,   // true
               -121,  // false
               10,    // false
               1234,  // false
               12321, // true
               2442}; // true

    for (i = 0; i < sizeof(test) / sizeof(int); i++)
        printf("%d\t-->\t%s\n", test[i], isPalindrome(test[i]) ? "true" : "false");

    return 0;
}

bool isPalindrome(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;

    int rev = 0;
    while (rev < x)
    {
        rev = rev * 10 + (x % 10);
        if (rev == x)
            return true;
        x /= 10;
    }

    return rev == x;
}