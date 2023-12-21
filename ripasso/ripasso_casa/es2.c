#include<stdio.h>

float media(int T[], int n)
{
    int max=T[0], min=T[0], i, gg=0;
    float tot=0;

    for (i=0; i<n; i++)
    {
        tot += T[i];
    }

    float media = tot/n;
    return media;    
}

int max(int T[], int n)
{
    int max = T[0];
    for (int i=0; i<n; i++)
    {
        if (T[i] >= max)
        {
            max = T[i];
        }
    }
    return max;
}

int min(int T[], int n)
{
    int min = T[0];
    for (int i=0; i<n; i++)
    {
        if (T[i] <= min)
        {
            min = T[i];
        }
    }
    return min;
}

int giorni(int T[], int n)
{
    int gg = 0;
    for (int i=0; i<n; i++)
    {
        if (T[i] >= 15 && T[i] <= 25)
        {
            gg++;
        }
    }
    return gg;
}

void main()
{

int n, i;

printf ("\n\nInserire il numero di giorni (lunghezza del vettore):\t");
scanf ("%d", &n);

int T[n];

printf ("\n\nRiempire il vettore con le Temperature.\n");
for (i=0;i<n;i++)
{
    printf ("\nInserire la Temperatura del giorno %d:\t", i);
    scanf ("%d", &T[i]);
}

printf ("\n\nLa temperatura massima negli ultimi %d gioni e' stata di %d gradi mentre quella minima e' stata di %d gradi.", n, max(T, n), min(T, n));
printf ("\nMetre la temperatura media si aggirava intorno ai %f gradi.\nInfine i giorni con una temperatura compresa tra 15 e 25 gradi sono %d.\n\n", media(T, n), giorni(T, n));

}