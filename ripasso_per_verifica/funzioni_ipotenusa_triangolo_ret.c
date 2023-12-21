#include<stdio.h>
#include<math.h>

float cal_ipo (float cat, float Cat)
{
    float ipo = hypot(cat, Cat);
    return(ipo);
}

float cal_P (float cat, float Cat, float ipo)
{
    float Perimetro = cat + Cat + ipo;
    return(Perimetro);
}

float cal_A (float cat, float Cat)
{
    float Area = (cat * Cat)/2;
    return(Area);
}

void main()
{

float c, C, i, P, A;

printf ("\n\nInserire il cateto minore:\t");
scanf ("%f",&c);
printf ("\n\nInserire il cateto maggiore:\t");
scanf ("%f",&C);

i = cal_ipo (c, C);
P = cal_P (c, C, i);
A = cal_A (c, C);

printf ("\n\nL'ipotennusa e':\t%f\nIl perimetro e':\t%f\nL'area e':\t%f", i, P, A);

    return(0);
}