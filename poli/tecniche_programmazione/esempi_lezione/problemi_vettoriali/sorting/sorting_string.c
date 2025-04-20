#include <stdio.h>
#include <string.h>

#define N 10
#define MAX_LEN_STRING 10

void ordinaNomi(char n[][MAX_LEN_STRING + 1], int l);
void print_arr(char n[][MAX_LEN_STRING + 1], int l);

int main(void)
{
    char names[N][MAX_LEN_STRING + 1] = {"Charlie", "Alice", "Eve", "Bob", "Grace", "Diana", "Jack", "Frank", "Hank", "Ivy"};

    printf("\nBefore:\n");
    print_arr(names, sizeof(names) / sizeof(names[0]));

    ordinaNomi(names, sizeof(names) / sizeof(names[0]));

    printf("\nAfter:\n");
    print_arr(names, sizeof(names) / sizeof(names[0]));

    return 0;
}

void ordinaNomi(char n[][MAX_LEN_STRING + 1], int l)
{
    int i, min, j;
    char tmp[MAX_LEN_STRING + 1];
    for (i = 0; i < l - 1; i++)
    {
        min = i;
        for (j = i + 1; j < l; j++)
            if (strcmp(n[j], n[min]) < 0)
                min = j;

        if (min != i)
        {
            strcpy(tmp, n[i]);
            strcpy(n[i], n[min]);
            strcpy(n[min], tmp);
        }
    }
}

void print_arr(char n[][MAX_LEN_STRING + 1], int l)
{
    for (int i = 0; i < l; i++)
        printf("\t%s\n", n[i]);
}