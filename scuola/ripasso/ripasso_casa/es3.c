#include<stdio.h>
#include<math.h>

void risultati(int b, int h)
{
    float ipo = hypot(b, h);
    printf ("\n\nL'ipotenusa del triangolo rettangolo e':\t%f", ipo);

    float P = b + h + ipo;
    printf ("\nIl perimetro del triangolo rettangolo e':\t%f", P);

    float A = (b * h) / 2;
    printf ("\nL'area del triangolo rettangolo e':\t%f\n\n", A);
}

void main()
{

int b, h;

printf ("\n\nInserire il valore della base:\t");
scanf ("%d",&b);
printf ("\nInserire il valore dell'altezza:\t");
scanf ("%d",&h);

risultati(b, h);

}