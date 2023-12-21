#include<stdio.h>
#define pg 3.14

int cal_quad(int b)
{
    int a_quad = b*b;
    return(a_quad);
}

int cal_ret(int b, int h)
{
    int a_ret = b*h;
    return(a_ret);
}

float cal_cer(int r)
{
    float a_cer = r*r*pg;
    return(a_cer);
}

void main()
{

char scelta;

printf ("\n\nInserire il Q per selezionare il quadrato, R per il rettangolo, e C per il cerchio:\t");
scanf ("%s",&scelta);

int b, quadrato, h, rettangolo;
int r, cerchio;

switch (scelta)
{
case 'Q':

printf ("\nInserire la base del quadrato:\t");
scanf ("%d",&b);
quadrato = cal_quad (b);
printf ("\n\nL'area del quadrato e':\t%d",quadrato);
    break;

case 'R':

printf ("\nInserire la base del rettangolo:\t");
scanf ("%d",&b);
printf ("\nInserire l'altezza del rettagolo:\t");
scanf ("%d",&h);
rettangolo = cal_ret (b, h);
printf ("\n\nL'area del quadrato e':\t%d",rettangolo);
    break;

case 'C':

printf ("\nInserire il raggio:\t");
scanf ("%d",&r);
cerchio = cal_cer (r);
printf ("\n\nL'area del quadrato e':\t%d",cerchio);
    break;    

default:
    break;

}








}