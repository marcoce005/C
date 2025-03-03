#include<stdio.h>
 main ()
 {
 int a, b, c;
printf ("\nIl programma calcola se i tre numeri appartengono ad una terna pitagorica\n\n");
 printf("Inserire il primo numero:  ");
 scanf ("%d", &a);
 printf("Inserire il secondo numero:    ");
 scanf ("%d", &b);
 printf("Inserire il terzo numero:  ");
 scanf ("%d", &c);
 if (a*a+b*b==c*c)
 {
 printf ("si tratta di una terna pitagorica");
 }
 else 
 {
 printf ("non si tratta di una terna pitagorica");
 }


return(0);
 sleep (5000);
}
