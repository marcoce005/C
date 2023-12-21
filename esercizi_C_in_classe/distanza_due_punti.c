#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void main()
{

int x1,x2,y1,y2;
float R;

printf ("\nInserire le coordinate dei due punti.");
printf ("\n\nInserire le coordinate del primo punto:    ");
scanf ("%d",&x1);
scanf ("%d",&y1);
printf ("\n\nInserire le coordinate del secondo punto:    ");
scanf ("%d",&x2);
scanf ("%d",&y2);
R=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
printf ("\n\nLa distanza tra le coordinate (%d, %d) e (%d, %d) e' %f",x1,x2,y1,y2,R);

sleep (5);
    return(0);
}