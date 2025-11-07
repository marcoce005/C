#include <stdio.h>
#include "lib.h"

char *ciro(void)
{
    return "ciro\n";
}

char *gianni(void)
{
    return "gianni";
}

void f(void)
{
    for (int i = 0; i < 10; i++)
        printf("%d\t", i + 1);
}