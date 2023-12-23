#include <stdio.h>
#include<stdlib.h>

#define NBITS  4    // numero di bit per la codifica FLC
#define NCODES 4    // numero di codici dell'alfabeto

int n_combinazioni()    //calcolo il numero di accoppiamenti possibili
{
    int tot=0;
    for (int i = 1; i < NCODES; i++)
    {
        tot += NCODES - i;
    }
    return(tot);
}

void print_code(int arr_dist[], int combinazioni)   //stampo l'array delle distanze
{
    for (int i = 0; i < combinazioni; i++)
    {
        printf("\nDistanza combianzione %d:\t%d", i+1, arr_dist[i]);
    }
}

int d_hamming(int mat[NCODES] [NBITS], int j, int k)    //calcolo la distanza di hamming tra una riga e l'altra
{
    int cont=0;
    for (int i = 0; i < NBITS; i++)
    {
        if (mat[j] [i] + mat[k] [i] == 1)
        {
            cont++;
        } 
    }
    return(cont);
}

void main() 
{
    int codec[NCODES] [NBITS] = 
    {
        {1, 0, 1, 1},   // codifica del simbolo 1
        {0, 1, 1, 0},   // codifica del simbolo 2
        {1, 0, 0, 1},   // codifica del simbolo 3
        {0, 1, 0, 1},   // codifica del simbolo 4
    };

    int combinazioni = n_combinazioni(), arr_dist[combinazioni], y=0;

    for (int i = 0; i < NCODES; i++)        //eseguo tutte le combianzioni delle coppie
    {
        for (int x = i+1; x < NCODES; x++)
        {
            arr_dist[y++] = d_hamming(codec, i, x);     //riempo l'array con le rispettive distanze
        }
    }

    print_code(arr_dist, combinazioni);
}