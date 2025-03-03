#include<stdio.h>
#define pigreco 3.14
#include<stdlib.h>

void main()
{

int figura,i;
float n,P=0,b,h,lq,A=1;

printf ("\nDigitare 1 per selezionare il Triangolo, 2 per selzionare il Quadrato, 3 per selezionare il Cerchio: ");
scanf ("%1d",&figura);

switch (figura)
{
case 1:
        printf ("\n\nHai selezionato il Triangolo.\nInserisci la base, l'altezza e il lato obliquo:\n");
        scanf ("%f",&b);
        scanf ("%f",&h);
        scanf ("%f",&lq);
        printf ("\n\nIl Perimetro e l'Area del Triangolo sono:  %f e %f",b+h+lq,((b*h)/2));
        
break;

case 2:
        printf ("\n\nHai selezionato il Rettangolo.\nInserisci la base e l'altezza:\n");
        for (i=1;i<=2;i++)
        {
            scanf ("%f",&n);
            P=P+n;
            A=A*n;    
        }
        printf ("\n\nIl Perimetro e l'Area del Rettangolo sono:  %f e %f",P*2,A);
break;
case 3:
        printf ("\n\nHai selezionato il Cerchio.\nInserisci il raggio:\n");
        scanf ("%f",&n);
        printf ("\n\nLa Cinrconferenza e l'Area del Cerchio sono:  %f e %f",(n*2)*pigreco,(pow(n,2))*pigreco);
break;

default:
break;
}

















    return(0);
}