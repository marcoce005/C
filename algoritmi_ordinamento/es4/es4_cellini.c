#include<stdio.h>
#include<stdlib.h>

FILE *numeri, *out;

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

void clean()
{
    remove ("./output.txt");
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
    for (int i = 0; i < l; i++)
    {
        fprintf (out, "%d\n", arr[i]);
    }
}

int main()
{
    control();
    clean();

    numeri = fopen ("./numeri.txt", "rt");
    out = fopen ("./output.txt", "at");
    
    int l = countline();

    int arr[l], i=0;
    while (! feof(numeri))
    {
        fscanf (numeri, "%d\n", &arr[i++]);
    }
    
    qsort (arr, l, sizeof (int), cmpfunc);
    
    print(arr, l);

    fclose(numeri);
    fclose(out);

    return 0;
}