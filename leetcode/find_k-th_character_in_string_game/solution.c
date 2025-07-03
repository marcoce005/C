#include <stdio.h>
#include <string.h>

char kth_character(int k);

int main(void)
{
    int k = 5;

    printf("k = %d --> %c\n", k, kth_character(k));             // must be == to 'b'
    k = 10;
    printf("k = %d --> %c\n", k, kth_character(k));             // must be == to 'c'
    
    return 0;
}

char kth_character(int k)
{
    // Simply version

    // int i, len;
    // char word[1000] = "a";
    // while (!isalpha(word[k - 1]))
    // {
    //     len = strlen(word);
    //     for (i = len; i < len * 2; i++)
    //         word[i] = word[i - len] == 'z' ? 'a' : word[i - len] + 1;
    // }
    // return word[k - 1];


    // Optimized version 
    // the number of letters changed is equal to the amount of 1's that there are in the k-1 number in binary notation

    int count = 0;
    k--;
    while (k != 0)
    {
        count += k % 2;
        k /= 2;
    }
    return 'a' + count;
}