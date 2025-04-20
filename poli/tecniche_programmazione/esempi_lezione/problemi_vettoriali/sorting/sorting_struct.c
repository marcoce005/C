#include <stdio.h>

#define N 10
#define MAX_NAME 30

typedef struct Student
{
    int id;
    char name[MAX_NAME + 1];
    float gpa;
} student;

void ordineStudenti(student n[], int l);
void print_arr(student n[], int l);

int main(void)
{
    student list[N] = {
        {1001, "Alice", 3.5},
        {1023, "Bob", 3.8},
        {1045, "Charlie", 2.9},
        {1078, "Diana", 3.7},
        {1099, "Eve", 3.2},
        {1134, "Frank", 3.0},
        {1176, "Grace", 3.9},
        {1208, "Hank", 2.8},
        {1250, "Ivy", 3.6},
        {1304, "Jack", 3.4}};

    printf("\nBefore:\n");
    print_arr(list, sizeof(list) / sizeof(list[0]));

    ordineStudenti(list, sizeof(list) / sizeof(list[0]));

    printf("\nAfter:\n");
    print_arr(list, sizeof(list) / sizeof(list[0]));

    return 0;
}

void ordineStudenti(student s[], int l)
{
    int i, min, j;
    student tmp;
    for (i = 0; i < l - 1; i++)
    {
        min = i;
        for (j = i + 1; j < l; j++)
            if (s[j].gpa < s[min].gpa)
                min = j;

        if (min != i)
        {
            tmp = s[i];
            s[i] = s[min];
            s[min] = tmp;
        }
    }
}

void print_arr(student s[], int l)
{
    for (int i = 0; i < l; i++)
        printf("%d\t%s\t%.2f\n", s[i].id, s[i].name, s[i].gpa);
}