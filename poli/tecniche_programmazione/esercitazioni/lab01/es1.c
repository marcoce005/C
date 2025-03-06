#include <stdio.h>

int main(void)
{
    int x, y;
    float z;

    printf("Insert an integer number:\t");
    scanf("%d", &x);
    y = 3;
    z = (float)(x) / y; // is the same of doing: (float) x / y

    printf("%d/%d = %f", x, y, z);

    return 0;
}