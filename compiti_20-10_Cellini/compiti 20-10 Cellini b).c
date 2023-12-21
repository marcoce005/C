#include <stdio.h>

void main()
{
int l1,l2,l3;

printf ("\nQuesto programma verifica se i lati inseriti possono creare un triangolo e dice di che tipologia si tratta\n\n");
printf ("Inserire il primo lato:\n");
scanf ("%d",&l1);
printf ("\n\nInserire il secondo lato:\n");
scanf ("%d",&l2);
printf ("\n\nInserire il terzo lato:\n");
scanf ("%d",&l3);

if (l1==l2 && l2==l3)
       printf("Il triangolo e' equilatero\n\n");
  else if(l1==l2 || l2==l3 || l1==l3)
       printf("Il triangolo e' isoscele\n\n");
  else printf("Il triangolo e' scaleno\n\n");



    return(0);
    sleep (5000);
}