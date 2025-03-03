#include<stdio.h>

void main()
{

int n,m,x,tot=0,min,max=0,i=0;
float media;

printf ("Inserire due numeri da tastiera indicanti un intervallo.\nCalcolare la somme  e la media di tutti i numeri inseriti compresi nell'intervallo.\nL'inserimento dello 0 causa la terminazione del programma.");
printf ("\n\nInserire il primo numero numero:     ");
scanf ("%d",&n);
printf ("\n\nInserire il primo secondo numero:     ");
scanf ("%d",&m);

while (n==m)
{
    printf ("\n\nNumeri non validi riprovare");
    printf ("\n\nInserire il primo numero numero:     ");
    scanf ("%d",&n);
    printf ("\n\nInserire il primo secondo numero:     ");
    scanf ("%d",&m);
}


while (x!=0)
{

printf ("\n\nInserire il valore da verificare se e' compreso:   ");
scanf ("%d",&x);

if ((x>n && x<m) || (x>m && x<n))
{
    i++;
    tot=tot+x;
    
}
else
{i--;}


}

media=(float)tot/5;

printf ("\n\nIl totale e':  %d",tot);
printf ("\nLa media e':     %f",media);



    return(0);
}