#include <stdio.h>

void main()
{

int n,n2,r;

printf ("\nIl programma calcola se il primo numero e' multiplo dell'altro\n\n");
printf ("Inserire il primo numero: \n");
scanf ("%d", &n);
printf ("\n\nInserire il secondo numero: \n");
scanf ("%d",&n2);

r=n%n2;

if (r==0)
{
    printf ("\n\nIl primo numero e' multiplo del secondo, il numero e':%d", n);

}
else{}

 if (r!=0)
 {
    printf ("\n\nIl primo numero non e' multiplo del secondo\n\n");
}
else{}


return(0);
sleep (5000);


}