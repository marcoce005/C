#include <stdio.h>
#define pigreco 3.14

void main()
{
int n,A_q;
float A_c;

printf ("\nQuesto programma confornta le aree di un quadrato e di un cerchio con lato e raggio uguale.");
printf ("\n\nInserire il numero che corrisponde al lato del quadrato e al raggio del cercio:    ");
scanf ("%d",&n);

if (n*n==n*n*pigreco)
{
    printf ("\n\nLe due aree sono uguali");
}
else if (n*n>n*n*pigreco)
{
    printf ("\n\nL'area maggiore e' quella del quadrato");
}
else
{
    printf ("\n\nL'area maggiore e' quella del cerchio");
}




    return(0);
}