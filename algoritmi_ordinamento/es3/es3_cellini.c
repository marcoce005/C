#include<stdio.h>
#include<stdlib.h>

FILE *numeri;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void control()
{
    if (fopen ("./numeri.txt", "r") == NULL)
    {
        printf ("\n\nFile non esistente!!!\n\n");
        exit(1);
    }
}

int countline()
{
    int tot=0;
    char c;
    for (c = getc(numeri); c != EOF; c =getc (numeri))
        if (c == '\n')
            ++tot;
    fclose(numeri);
    numeri = fopen ("./numeri.txt", "rt");
    return tot+1;
}

void print(int arr[], int l)
{
    printf ("\n\nNumeri ordinati:\n");
    for (int i = 0; i < l; i++)
    {
        printf ("%i\n", arr[i]);
    }
}

int main()
{
    control();
    
    numeri = fopen ("./numeri.txt", "rt");
    
    int l = countline();

    int arr[l], i=0;
    while (! feof(numeri))
    {
        fscanf (numeri, "%d\n", &arr[i++]);
    }
    
    qsort (arr, l, sizeof (int), cmpfunc);
    
    print(arr, l);

    fclose(numeri);

    return 0;
}