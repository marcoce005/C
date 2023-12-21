#include<stdio.h>

void main()
{

int anno;

printf ("\n\nInserire l'anno:\t");
scanf ("%d", &anno);

if (anno < 0)
{
    printf ("\n\nAnno non valido.");
}
else
{
    while (anno != 0)           //solo all'inserimento dello zero il programma termina
    {
        if (anno % 4 == 0 && anno % 100 != 0 || anno % 400 == 0)
        {
            printf ("\nAnno bisestile.");
        }  
        else
        {
            printf ("\nAnno non bisestile.");
        } 

        printf ("\n\nInserire l'anno:\t");
        scanf ("%d", &anno);
    }
}

}