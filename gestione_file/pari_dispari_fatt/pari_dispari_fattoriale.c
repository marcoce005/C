#include<stdio.h>
#include<stdlib.h>

void control()
{
    if (fopen ("./numeri.txt", "r") == NULL)
    {
        printf ("\n\nFile non presente!!!");
        exit(1);
    }
}

void clean()
{
    remove("./pari.txt");
    remove("./dispari.txt");
    remove("./fattoriale.txt");
}

long long int fatt(int n)
{
    long long int tot = 1;
    if (n == 0)
        return 1;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            tot *= i;
        }
        return tot;
    }
}

int main()
{
    FILE *numeri, *pari, *dispari, *fattoriale;

    control();
    clean();

    numeri = fopen ("./numeri.txt", "r");
    pari = fopen ("./pari.txt", "a"); 
    dispari = fopen ("./dispari.txt", "a");
    fattoriale = fopen ("./fattoriale.txt", "a");

    int n; 
    long long int f;

    while (!feof(numeri))
    {
        fscanf (numeri, "%d\n", &n);
        if (n % 2 == 0)
            fprintf (pari, "%d\n", n);
        else
            fprintf (dispari, "%d\n", n); 
        fprintf (fattoriale, "%lld\n", fatt(n));
    }
    
    fclose(numeri);
    fclose(pari);
    fclose(dispari);
    fclose(fattoriale);

    return 0;
}
