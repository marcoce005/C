#include<stdio.h>

void main()
{

int n,m,x,tot=0,min,max=0,i=0;
float media;

printf ("\nQuesto programma permette di visualizzare tutti i numeri compresi tra un numero N e un numero M inseriti da tastiera fino al raggiungimento di 5 numeri validi.\nIl programma stamperà a video la somma e la media, di questi numeri. \nInoltre stamperà il valore massimo ed il valore minimo.");
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

if (n>m)
{
    min=n;
}

else
{
    min=m;
}



while (i<5)
{

printf ("\n\nInserire il valore da verificare se e' compreso:   ");
scanf ("%d",&x);

if ((x>n && x<m) || (x>m && x<n))
{
    i++;
    tot=tot+x;

    if (max>x)
    {

    }
    else
    {
        max=x;
    }

    if (min<x)
    {

    }
    else
    {
        min=x;
    }    
}
else
{}


}

media=(float)tot/5;

printf ("\n\nIl totale e':  %d",tot);
printf ("\nLa media e':     %f",media);
printf ("\nIl massimo e':   %d",max);
printf ("\nIl minimo e':   %d",min);





    return(0);
}