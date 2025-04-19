#include <stdio.h>
#include <string.h>

#define STUDENTS_FILE "./students.txt"
#define NMAX 30
#define MMAX 6
#define MAX_STUDENTS 100

typedef struct Student
{
    char id[MMAX + 1];
    char name[NMAX + 1];
} student;

int get_students(student l[]);
void get_name(student l[], int len, char id[], char ans[]);

int main(void)
{
    student list[100];
    char str[NMAX], ans[NMAX];
    int numb_students = get_students(list);

    if (numb_students < 0)
        return -1;

    printf("\nInsert id's studet:\t");
    scanf("%s", str);

    get_name(list, numb_students, str, ans);

    if (ans[0] == '\0')
        printf("\nStudent #%s not found.", str);
    else
        printf("\n#%s --> %s", str, ans);

    return 0;
}

void get_name(student l[], int len, char id[], char ans[])
{
    for (int i = 0; i < len; i++)
        if (strcmp(l[i].id, id) == 0)
        {
            strcpy(ans, l[i].name);
            return;
        }
    ans[0] = '\0';
}

int get_students(student l[])
{
    FILE *in;

    in = fopen(STUDENTS_FILE, "r");

    if (in == NULL)
    {
        printf("\nFile error");
        return -1;
    }

    int i = 0;
    char id[MMAX * 2];
    while (i < MAX_STUDENTS && fscanf(in, "%s", id) == 1)
    {
        if (strlen(id) > MMAX)
        {
            printf("\nError in line %d:\tincorrect id %s", i + 1, id);
            return -1;
        }
        strcpy(l[i].id, id);
        fgets(l[i++].name, NMAX, in);
    }
    return i;
}