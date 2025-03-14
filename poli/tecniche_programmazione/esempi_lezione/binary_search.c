#include <stdio.h>

#define LEN 10
#define VALUE 7

int binary_search(int v[LEN], int key);
void print_vet(int v[LEN]);

int main(void)
{
    int v[LEN];

    for (int i = 0; i < sizeof(v) / sizeof(int); i++)
        v[i] = i + 1;

    int element_index = binary_search(v, VALUE);

    printf("\nArray:\t");
    print_vet(v);

    printf("\nThe number %d ", VALUE);
    element_index >= 0 ? printf("it's located at the index:\t%d", element_index) : printf("was not found");

    return 0;
}

int binary_search(int v[LEN], int key)
{
    int start = 0, end = LEN - 1, middle;

    while (start <= end)
    {
        middle = (start + end) / 2;

        if (v[middle] == key)
            return middle;
        if (v[middle] < key)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}

// int binary_search(int v[LEN], int key)
// {
//     int start = 0, end = LEN - 1, found = 0, middle;

//     while (start <= end && found == 0)
//     {
//         middle = (start + end) / 2;

//         if (v[middle] == key)
//             found = 1;
//         if (v[middle] < key)
//             start = middle + 1;
//         else
//             end = middle - 1;
//     }
//     return found == 0 ? -1 : middle;
// }

void print_vet(int v[LEN])
{
    for (int i = 0; i < LEN; i++)
        printf(" %d", v[i]);
}