#include <stdio.h>

int majority(int *a, int N);

int main(void)
{
    int vet[] = {3, 3, 9, 4, 3, 5, 3},
        vet1[] = {0, 1, 0, 2, 3, 4, 0, 5};

    printf("vet --> %d\n", majority(vet, sizeof(vet) / sizeof(int)));
    printf("vet1 --> %d\n", majority(vet1, sizeof(vet1) / sizeof(int)));

    return 0;
}

int majority(int *a, int N)
{
    if (N == 1)
        return *a;

    int mj_left = majority(a, N / 2),
        mj_right = majority(a + (N / 2), N - (N / 2)),
        cnt_left = 0,
        cnt_right = 0;

    if (mj_left == mj_right)
        return mj_left;

    for (int i = 0; i < N; i++)
    {
        if (a[i] == mj_left)
            cnt_left++;
        if (a[i] == mj_right)
            cnt_right++;
    }

    if (cnt_left > N / 2)
        return mj_left;

    if (cnt_right > N / 2)
        return mj_right;

    return -1;
}