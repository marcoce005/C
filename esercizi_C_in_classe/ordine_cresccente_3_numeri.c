#include <stdio.h>

void main ()
{
    float n1,n2,n3;

printf ("\nIl programma mette i tre numeri in ordine crescente");
printf ("\n\nInserire il primo numero: ");
scanf ("%f",&n1);
printf ("\n\nInserire il secondo numero: ");
scanf ("%f",&n2);
printf ("\n\nInserire il terzo numero: ");
scanf ("%f",&n3);

if (n1<=n2 && n1<=n3)   //vedo se n1 è il più piccolo
{
    printf ("\n\nI numeri in ordine crescente sono: %f",n1);
    if (n2<=n3)     //verifico qual'é il secondo numero più piccolo
    {
        printf (" %f",n2);
        printf (" %f",n3);
    }
    else
    {
        printf (" %f",n3);
        printf (" %f",n2);
    }
}
else if (n2<=n1 && n2<=n3)  //altrimenti vedo se n2 è il più piccolo
{
    printf ("\n\nI numeri in ordine crescente sono: %f",n2);
    if (n1<=n3)     //verifico qual'é il secondo numero più piccolo
    {
        printf (" %f",n1);
        printf (" %f",n3);
    }
    else
    {
        printf (" %f",n3);
        printf (" %f",n1);
    }
}
else    //altrimenti il più piccolo è n3
{
    printf ("\n\nI numeri in ordine crescente sono: %f",n3);
    if (n2<=n1)     //verifico qual'é il secondo numero più piccolo
    {
        printf (" %f",n2);
        printf (" %f",n1);
    }
    else
    {
        printf (" %f",n1);
        printf (" %f",n2);
    }
}




sleep (5);
return(0);
}