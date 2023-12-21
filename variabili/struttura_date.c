#include <stdio.h>

struct data{
int giorno;
int mese;
int anno;
}c1,c2;

int main()
{
    int g,m,a;
    printf("\n\nIntrodurre il giorno del compleanno:\t");
    scanf("%d", & g);
    printf("\nIntrodurre il mese del compleanno:\t");
    scanf("%d", & m);
    printf("\nIntrodurre l'anno del compleanno:\t");
    scanf("%d", & a);
    struct data c1={g,m,a};

    printf("\n\nIntrodurre il giorno del compleanno:\t");
    scanf("%d", & g);
    printf("\nIntrodurre il mese del compleanno:\t");
    scanf("%d", & m);
    printf("\nIntrodurre l'anno del compleanno:\t");
    scanf("%d", & a);
    struct data c2={g,m,a};

        if(c1.anno==c2.anno)
        {
            if(c1.mese==c2.mese)
                    {
                        if(c1.giorno==c2.giorno)
                            {printf("\n\nLe due persone sono nate lo stesso giorno!");}
                        else
                       {
                            if(c1.giorno<c2.giorno)
                            {printf("\n\nLa prima persona e' piu' vecchia");}
                            else
                            {printf("\n\nLa seconda persona e' piu' vecchia");}
                        }
                       
                    }
            else
            {
                    if(c1.mese<c2.mese)
                        {printf("\n\nLa prima persona e' piu' vecchia");}
                            else
                        {printf("\n\nLa seconda persona e' piu' vecchia");}
            }
        }
    else
    {
        if (c1.anno<c2.anno)
            {
                printf("\n\nLa prima persona e' piu' vecchia");
            }
            else
            {
                printf("\n\nLa seconda persona e' piu' vecchia");
            }

    }


       
       
    return 0;
}