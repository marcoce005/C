#include<stdio.h>

int calcolaP(int l)
{
    int perimetro = l*4;
    return(perimetro);
}

int calcolaA(int l)
{
    int area = l*l;
    return(area);
}

int calcolaV(int l)
{
    int volume = l*l*l;
    return(volume);
}

void main()
{

int l, perimetro, volume, area;

printf ("\n\nInserire il lato del quadrato:\t");
scanf ("%d",&l);

perimetro = calcolaP (l);
area = calcolaA (l);
volume = calcolaV (l);

printf ("\n\nIl perimetro del quadrato e':\t%d\nL'area e':\t%d\nIl volume del cubo e':\t%d",perimetro,area,volume);

















    return(0);
}