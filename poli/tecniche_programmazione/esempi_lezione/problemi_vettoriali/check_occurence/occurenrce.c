#include <stdio.h>

#define FILE_PATH "./input2.txt"
#define MAX_LEN 256
#define MAX_DISTANCE_PERCENTAGE 1

int check_sequence(FILE *in, float v[]); // 1 if each data have an occurence else 0 [-1 in case if error]
float my_abs(float n);
float relative_distance(float a, float b);

int main(void)
{
    FILE *in;
    float v[MAX_LEN];
    int ans;

    in = fopen(FILE_PATH, "r");

    ans = check_sequence(in, v);

    if (ans < 0)
    {
        fclose(in);
        printf("\nFile error!!!");
        return -1;
    }
    else if (ans)
        printf("\nAll number have an occurence");
    else
        printf("\nNot all number have an occurence");

    fclose(in);

    return 0;
}

int check_sequence(FILE *in, float v[])
{
    if (in == NULL)
        return -1;

    int len, i, j;

    fscanf(in, "%d", &len);

    len = len > MAX_LEN ? MAX_LEN : len;

    for (i = 0; i < len; i++)
        fscanf(in, "%f", &v[i]);

    for (i = 0; i < len; i++)
        for (j = 0; j < len; j++)
            if (relative_distance(v[i], v[j]) > (MAX_DISTANCE_PERCENTAGE / 100.0))
                return 0;
    return 1;
}

float relative_distance(float a, float b)
{
    if (b > a)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    return my_abs(a - b) / my_abs(a);
}

float my_abs(float n) { return n < 0 ? -1 * n : n; }