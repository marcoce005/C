#include <stdio.h>

#define SEQ_PATH "./sort1.txt"
#define MAX_LEN 100 + 1 // take care of the sequence's len

int get_sequences(FILE *in, int *s, int m[][MAX_LEN]);
void print_sequence(int m[][MAX_LEN], int l);
void clone_arr(int v[], int l, int m[][MAX_LEN], int times);
void selection_sort(int v[], int len);
void insertion_sort(int v[], int len);
void shell_sort_knuth(int v[], int len);

int main(void)
{
    FILE *fp_seq;
    int sequences[MAX_LEN][MAX_LEN], S, ans, copy_arr[3][MAX_LEN];

    fp_seq = fopen(SEQ_PATH, "r");
    ans = get_sequences(fp_seq, &S, sequences);

    if (ans < 0)
    {
        fclose(fp_seq);
        return -1;
    }

    for (int i = 0; i < S; i++)
    {
        clone_arr(&sequences[i][1], sequences[i][0], copy_arr, 3);

        printf("\n\t\t\tSelection sort\n");
        selection_sort(copy_arr[0], sequences[i][0]);
        
        printf("\n\n\t\t\tInsertion sort\n");
        insertion_sort(copy_arr[1], sequences[i][0]);
        
        printf("\n\n\t\t\tShell sort\n");
        shell_sort_knuth(&sequences[i][1], sequences[i][0]);
    }

    fclose(fp_seq);
    return 0;
}

void clone_arr(int v[], int l, int m[][MAX_LEN], int times) {
    int i, j;
    for (i = 0; i < times; i++)
        for (j = 0; j < l; j++, m[i][j] = v[j]);
}

void shell_sort_knuth(int v[], int len)
{
    int index, tmp, gap = 1, swap = 0, it_ext = 0, it_int, it_tot = 0;

    while ((gap * 3) + 1 <= len)
        gap = (gap * 3) + 1;

    while (gap >= 1)
    {
        it_ext++;
        for (int i = gap; i < len; i++)
        {
            index = i;
            tmp = v[i];
            it_int = 0;
            while (index >= gap && tmp < v[index - gap])
            {
                it_int++;
                swap++;
                v[index] = v[index - gap];
                index -= gap;
            }

            it_tot += it_int;
            printf("\nIteration %d: inter --> %d", i + 1, it_int);
            swap++;
            v[index] = tmp;
        }
        gap = (gap - 1) / 3; // or gap /= 3
    }

    printf("\n\nExternal iteration:\t%d", it_ext);
    printf("\nSwaps:\t%d", swap);
    printf("\nTot iteration:\t%d", it_tot);
}

void insertion_sort(int v[], int len)
{
    int index, tmp, swap = 0, it_ext = 0, it_int, it_tot = 0;
    for (int i = 1; i < len; i++, it_ext++)
    {
        index = i;
        tmp = v[i];
        it_int = 0;
        while (index > 0 && tmp < v[index - 1])
        {
            it_int++;
            swap++;
            v[index] = v[index - 1]; // make space for the new number
            index--;
        }
        swap++;
        v[index] = tmp;

        it_tot += it_int;
        printf("\nIteration %d: inter --> %d", i + 1, it_int);
    }

    printf("\n\nExternal iteration:\t%d", it_ext);
    printf("\nSwaps:\t%d", swap);
    printf("\nTot iteration:\t%d", it_tot);
}

void selection_sort(int v[], int len)
{
    int i, j, index_min, tmp, swap = 0, it_ext = 0, it_int, it_tot = 0;
    for (i = 0; i < len - 1; i++, it_ext++)
    {
        index_min = i;
        for (j = i + 1, it_int = 0; j < len; j++, it_int++)
            if (v[j] < v[index_min])
                index_min = j;

        if (i != index_min)
        {
            swap++;
            tmp = v[i];
            v[i] = v[index_min];
            v[index_min] = tmp;
        }

        it_tot += it_int;
        printf("\nIteration %d: inter --> %d", i + 1, it_int);
    }

    printf("\n\nExternal iteration:\t%d", it_ext);
    printf("\nSwaps:\t%d", swap);
    printf("\nTot iteration:\t%d", it_tot);
}

int get_sequences(FILE *in, int *s, int m[][MAX_LEN])
{
    if (in == NULL)
    {
        printf("\nFile Error\nFile %s not found.\n");
        return -1;
    }

    fscanf(in, "%d", s);

    if (*s <= 0 || *s > MAX_LEN - 1)
    {
        printf("\nParameter Error\nSequence have to be between 0 and 100");
        return -1;
    }

    int i, j;

    for (i = 0; i < *s; i++)
    {
        fscanf(in, "%d", &m[i][0]);

        if (m[i][0] <= 0 || m[i][0] > MAX_LEN - 1)
        {
            printf("\nParameter Error\nElement in sequence have to be between 0 and 100");
            return -1;
        }

        for (j = 1; j <= m[i][0]; j++)
            fscanf(in, "%d", &m[i][j]);
    }
    return 0;
}

void print_sequence(int m[][MAX_LEN], int l)
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 1; j <= m[i][0]; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}