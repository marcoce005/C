#include<stdio.h>

struct materie
{
    int mate;
    int ita;
    int tpsi;
    int reti;
    int informatica;
}p1,p2;


void main()
{

int mate,ita,tpsi,reti,informatica,media1,media2;

printf ("\n\nInserire i voti della prima persona");

printf ("\nVoto di matematica =\t");
scanf ("%d",&mate);
printf ("\nVoto di italiana =\t");
scanf ("%d",&ita);
printf ("\nVoto di tpsi =\t");
scanf ("%d",&tpsi);
printf ("\nVoto di reti =\t");
scanf ("%d",&reti);
printf ("\nVoto di informatica =\t");
scanf ("%d",&informatica);

struct materie p1={mate,ita,tpsi,reti,informatica};
media1=(mate+ita+tpsi+reti+informatica)/5;

printf ("\n\nInserire i voti della seconda persona");

printf ("\n\nVoto di matematica =\t");
scanf ("%d",&mate);
printf ("\nVoto di italiana =\t");
scanf ("%d",&ita);
printf ("\nVoto di tpsi =\t");
scanf ("%d",&tpsi);
printf ("\nVoto di reti =\t");
scanf ("%d",&reti);
printf ("\nVoto di informatica =\t");
scanf ("%d",&informatica);

struct materie p2={mate,ita,tpsi,reti,informatica};
media2=(mate+ita+tpsi+reti+informatica)/5;

if (media1>media2)
{
    printf ("\n\nLa prima persona ha la media piu' alta");
}
else
{
    printf ("\n\nLa seconda persona ha la media piu' alta"); 
}







}