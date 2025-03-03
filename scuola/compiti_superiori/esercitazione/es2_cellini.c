#include<stdio.h>

void calcola(int n, int m, int mat[n] [m])
{
    int cont=1, valore;
    for (int r=0; r<n; r++)
    {
        for (int c=0; c<m-1; c++)
        {
            if (mat[r] [c] == mat[r] [c+1])
            {
                cont++;
                valore = mat[r] [c];
            }
        }
        if (cont > 1)
        {
            break;
        }
    }

    printf ("\n\nFascia %d di lunghezza %d", valore, cont);
}

void main()
{

int n, m;

printf ("\n\nInserire le righe:\t");
scanf ("%d", &n);
printf ("\nInserire le colonne:\t");
scanf ("%d", &m);

int mat[n] [m], r, c;

printf ("\n\nRiempire la matrice.\n");
for (r=0; r<n; r++)
{
    printf ("\n%d riga\n", r+1);
    for (c=0; c<m; c++)
    {
        printf ("Inserire il numero:\t");
        scanf ("%d", &mat[r] [c]);
    }
}

calcola(n, m, mat);

}