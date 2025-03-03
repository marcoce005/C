#include<stdio.h>
#include<stdlib.h>

void calcola_monete(float tot)
{
    int vet_monete[8] = {0};
    while (tot != 0.000)
    {
        if (tot >= 2.0)
        {
            vet_monete[7]++;
            tot -= 2;
        }
        else if (tot >= 1.0)
        {
            vet_monete[6]++;
            tot -= 1;
        }
        else if (tot >= 0.50)
        {
            vet_monete[5]++;
            tot -= 0.5;
        }
        else if (tot >= 0.20)
        {
            vet_monete[4]++;
            tot -= 0.20;
        }
        else if (tot >= 0.10)
        {
            vet_monete[3]++;
            tot -= 0.10;
        }
        else if (tot >= 0.050)
        {
            vet_monete[2]++;
            tot -= 0.05;
        }
        else if (tot >= 0.020)
        {
            vet_monete[1]++;
            tot -= 0.02;
        }
        else if (tot >= 0.010)
        {
            vet_monete[0]++;
            tot -= 0.01;
        }
        else
        {
            break;
        }
    }
    printf ("\n\nServono %d monete da 2 euro, %d monete da 1 euro, %d monete da 50 centesimi, %d monete da 20 centesimi, %d monete da 10 centesimi, %d monete da 5 centesimi, %d monete da 2 centesimi e %d monete da 1 centesimo.", vet_monete[7], vet_monete[6], vet_monete[5], vet_monete[4], vet_monete[3], vet_monete[2], vet_monete[1], vet_monete[0]);  
}

int main()
{
    float a, b, tot;
    printf ("\n\nInserire il primo valore:\t");
    scanf_s ("%f.2", &a);
    printf ("\n\nInserire il secondo valore:\t");
    scanf_s ("%f.2", &b);
    tot = a + b;
    calcola_monete(tot);
}