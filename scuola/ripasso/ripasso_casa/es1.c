#include<stdio.h>
#include<math.h>

float x1(int a, int b, int c)
{
    float x1 = (-b + sqrt(pow(b, 2)-4*a*c))/(a*2);

    return x1; 
}

float x2(int a, int b, int c)
{
    float x2 = (-b - sqrt(pow(b, 2)-4*a*c))/(a*2);

    return x2; 
}

void main()
{

int a, b, c;

printf ("\n\nInserire il valore di a:\t");
scanf ("%d",&a);
printf ("\nInserire il valore di b:\t");
scanf ("%d",&b);
printf ("\nInserire il valore di c:\t");
scanf ("%d",&c);

printf ("\n\nI risultati sono:\t%f\t%f", x1(a, b, c), x2(a, b, c));


}