#include<stdio.h>
#include<stdlib.h>

FILE *temp;

int cmpfunc (const void * a, const void * b)
{
   return ( *(float*)a - *(float*)b );
}

void control()
{
    if (fopen ("./temperatura.txt", "r") == NULL)
    {
        printf ("\n\nFile non esistente!!!\n\n");
        exit(1);
    }
}

void apri()
{
    temp = fopen ("./temperatura.txt", "r");
}

int n_temp()
{
    int tot=0;
    char c;
    while (! feof(temp))
    {
        fscanf (temp, "%c ", &c);
        if (c == '.')
            ++tot;
    }
    fclose(temp);
    temp = fopen ("./temperatura.txt", "r");
    return tot;
}

void print(float temp[], int l)
{
    for (int i = 0; i < l; i++)
        printf ("%.1f\t", temp[i]);
}

int main()
{
    control();
    apri();

    int i=0, l = n_temp();
    float arr_temp[l];
    while (! feof(temp))
    {
        fscanf (temp, "%f", &arr_temp[i++]);
    }

    printf ("\n\nTemp iniziali:\n");
    print(arr_temp, l);
    printf ("\n\n");

    qsort (arr_temp, l, sizeof (float), cmpfunc);

    printf ("\n\nTemp ordinate:\n");
    print(arr_temp, l);
    printf ("\n\n");

    printf ("La temperatura minima e':\t%.1f\nLa temperatura massima e':\t%.1f\n\n", arr_temp[0], arr_temp[l-1]);

    fclose(temp);

    return 0;
}