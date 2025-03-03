#include<stdio.h>

int main()
{
    int n;

    printf ("\n\nInserire la dimensione della matrice:\t");
    scanf_s ("%d", &n);

    int r, c, y=1, mat[n] [n];

    if (n <= 0 || n > 10)
        printf ("\n\nDimensione non valida.");
    else
    {
        for (r=0; r<n; r++)
        {
            for (c=0; c<n; c++)
            {
                if (r==0 || r == n-1 || c==0 || c == n-1)
                    mat[r] [c] = 0;
                else
                mat[r] [c] = y++;
            }
        }
    }

    
}