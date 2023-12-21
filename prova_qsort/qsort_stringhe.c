#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int cstring_cmp(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
} 

void print(char **array, int l) 
{ 
    printf ("\n\n");
    for(int i = 0; i < l; i++) 
        printf("%s  ", array[i]);
    printf ("\n\n");
}

int main() 
{
    char *strings[] = { "casa", "zoccolo", "terra", "centauro", "armadio", "pavimento" };

    int l = sizeof(strings) / sizeof(char *);

    qsort(strings, l, sizeof(char *), cstring_cmp);

    print(strings, l);
    
    return 0;
} 