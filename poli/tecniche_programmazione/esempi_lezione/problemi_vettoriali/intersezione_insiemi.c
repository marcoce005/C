#include <stdio.h>

#define LEN 5

void fill_array(int v[], int len);
int intersection(int v1[], int len1, int v2[], int len2);

int main()
{
    int vet1[LEN], vet2[LEN], common_number;

    printf("\nFill the first array:\n");
    fill_array(vet1, sizeof(vet1) / sizeof(vet1[0]));
    printf("\nFill the second array:\n");
    fill_array(vet2, sizeof(vet2) / sizeof(vet2[0]));

    common_number = intersection(vet1, sizeof(vet1) / sizeof(vet1[0]), vet2, sizeof(vet2) / sizeof(vet2[0]));

    printf("\nCommon number:\n");
    for (int i = 0; i < common_number; i++)
        printf("%d ", vet1[i]);

    return 0;
}

int intersection(int v1[], int len1, int v2[], int len2)
{
    int ni = 0, found = 0;
    for (int i = 0; i < len1; i++)
    {
        found = 0;
        for (int j = 0; j < len2 && !found; j++)
            if (v1[i] == v2[j])
                found = 1;
        if (found)
            v1[ni++] = v1[i];
    }
    return ni;
}

void fill_array(int v[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("n%d --> ", i + 1);
        scanf("%d", &v[i]);
    }
}