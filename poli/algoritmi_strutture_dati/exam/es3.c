#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void disp(int pos, int n, int k, char *val, char *sol, char *s2, int *mark, int *exit)
{
    if (*exit)
        return;
    if (pos >= k)
    {
        if (strncmp(sol, s2, k) == 0) // modifica del comfronto delle stringhe per comparare solo n caratteri ovvero quelli di l2
            *exit = 1;
        return;
    }

    for (int i = 0; i < n && *exit == 0; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;
            sol[pos] = val[i];
            disp(pos + 1, n, k, val, sol, s2, mark, exit);
            mark[i] = 0;
        }
    }
}

int strContains(char *s1, char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2);
    char *sol = (char *)malloc(l2 * sizeof(char));
    int *mark = (int *)calloc(l1, sizeof(int));
    int exit = 0;

    disp(0, l1, l2, s1, sol, s2, mark, &exit);

    free(mark);
    free(sol);
    return exit;
}

int strContains_correct_version(char *s1, char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2);
    int i, j;
    for (i = j = 0; i < l1; i++)
    {
        if (s1[i] == s2[j])
            j++;
        if (j == l2)
            return 1;
    }
    return 0;
}

int main()
{
    char *test_s1[] = {"abcdef", "abcdef", "hello world", "programming"};
    char *test_s2[] = {"ace", "aec", "hlo", "gram"};
    int n = sizeof(test_s1) / sizeof(test_s1[0]);

    for (int i = 0; i < n; i++)
    {
        printf("Test %d: s1 = \"%s\", s2 = \"%s\" -> ", i + 1, test_s1[i], test_s2[i]);
        if (strContains(test_s1[i], test_s2[i]))
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }

    return 0;
}