#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "brani.txt"
#define MAX_LEN 255 + 1

typedef struct
{
    char **songs;
    int n_songs;
} friend;

friend *read_songs(int *n);
void print_friends(friend *l, int n);
void print_list_songs(char **l, int n, char *prefix);
void free_friends(friend *l, int n);
void free_sol(char **sol, int n);
int moltiplication(int pos, friend *l, char **sol, int n, int cnt);
char **init_sol(int n);

int main(void)
{
    int n_friends;
    friend *friends = read_songs(&n_friends);
    char **sol = init_sol(n_friends);

    moltiplication(0, friends, sol, n_friends, 0);

    free_friends(friends, n_friends);
    free_sol(sol, n_friends);
    return 0;
}

int moltiplication(int pos, friend *l, char **sol, int n, int cnt)
{
    int i;
    if (pos >= n)
    {
        printf("Possibility %d:\n", cnt + 1);
        print_list_songs(sol, n, "");
        printf("\n");
        return cnt + 1;
    }

    for (i = 0; i < l[pos].n_songs; i++)
    {
        strcpy(sol[pos], l[pos].songs[i]);
        cnt = moltiplication(pos + 1, l, sol, n, cnt);
    }
    return cnt;
}

void print_list_songs(char **l, int n, char *prefix)
{
    for (int i = 0; i < n; i++)
        printf("%s%s\n", prefix, l[i]);
}

void free_sol(char **sol, int n)
{
    for (int i = 0; i < n; free(sol[i]), i++)
        ;
    free(sol);
}

void free_friends(friend *l, int n)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < l[i].n_songs; free(l[i].songs[j]), j++) // free strings
            ;
        free(l[i].songs); // free array of strings
    }
    free(l); // free array of friends
}

char **init_sol(int n)
{
    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; l[i] = (char *)malloc(MAX_LEN * sizeof(char)), i++)
        ;
    return l;
}

void print_friends(friend *l, int n)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", l[i].n_songs);
        print_list_songs(l[i].songs, l[i].n_songs, "\t");
        printf("\n");
    }
}

friend *read_songs(int *n)
{
    FILE *fp = fopen(FILE_PATH, "r");
    friend *friends;
    int i, j;
    char tmp[MAX_LEN];

    if (fp == NULL)
    {
        printf("\nFile error.");
        exit(1);
    }

    fscanf(fp, "%d", n);
    friends = (friend *)malloc((*n) * sizeof(friend));

    for (i = 0; i < *n; i++)
    {
        fscanf(fp, "\t%d", &friends[i].n_songs);
        friends[i].songs = (char **)malloc(friends[i].n_songs * sizeof(char *));

        for (j = 0; j < friends[i].n_songs; j++)
        {
            fscanf(fp, "\t\t%s", tmp);
            friends[i].songs[j] = strndup(tmp, strlen(tmp) + 1);
        }
    }

    return friends;
}