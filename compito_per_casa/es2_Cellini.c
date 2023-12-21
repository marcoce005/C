#include<stdio.h>
#include<string.h>

void main()
{

printf ("\n\nIl progrmma quante lettere e che lettere ci sono nella parola.");

int lung,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0,cont;
char parola[20];

printf ("\nInsrire la parola:\t");
fgets (parola, sizeof(parola), stdin);

lung=strlen(parola)-1;

for (cont=0;cont<lung;cont++)
{
    switch (parola[cont])
    {
    case 'a':
            a++;
    break;
    case 'A':
            a++;
    break;
    case 'b':
            b++;
    break;
    case 'B':
            b++;
    break;
    case 'c':
            c++;
    break;
    case 'C':
            c++;
    break;
    case 'd':
            d++;
    break;
    case 'D':
            d++;
    break;
    case 'e':
            e++;
    break;
    case 'E':
            e++;
    break;
    case 'f':
            f++;
    break;
    case 'F':
            f++;
    break;
    case 'g':
            g++;
    break;
    case 'G':
            g++;
    break;
    case 'h':
            h++;
    break;
    case 'H':
            h++;
    break;
    case 'i':
            i++;
    break;
    case 'I':
            i++;
    break;
    case 'j':
            j++;
    break;
    case 'J':
            j++;
    break;
    case 'k':
            k++;
    break;
    case 'K':
            k++;
    break;
    case 'l':
            l++;
    break;
    case 'L':
            l++;
    break;
    case 'm':
            m++;
    break;
    case 'M':
            m++;
    break;
    case 'n':
            n++;
    break;
    case 'N':
            n++;
    break;
    case 'o':
            o++;
    break;
    case 'O':
            o++;
    break;
    case 'p':
            p++;
    break;
    case 'P':
            p++;
    break;
    case 'q':
            q++;
    break;
    case 'Q':
            q++;
    break;
    case 'r':
            r++;
    break;
    case 'R':
            r++;
    break;
    case 's':
            s++;
    break;
    case 'S':
            s++;
    break;
    case 't':
            t++;
    break;
    case 'T':
            t++;
    break;
    case 'u':
            u++;
    break;
    case 'U':
            u++;
    break;
    case 'v':
            v++;
    break;
    case 'V':
            v++;
    break;
    case 'w':
            w++;
    break;
    case 'W':
            w++;
    break;
    case 'x':
            x++;
    break;
    case 'X':
            x++;
    break;
    case 'y':
            y++;
    break;
    case 'Y':
            y++;
    break;
    case 'z':
            z++;
    break;
    case 'Z':
            z++;
    break;

    default:
    break;
    }
}


    
    
printf ("\n\nLe lettere A o a sono;\t%d",a);
printf ("\nLe lettere B o b sono:\t%d",b);
printf ("\nLe lettere C o c sono:\t%d",c);
printf ("\nLe lettere D o d sono:\t%d",d);
printf ("\nLe lettere E o e sono:\t%d",e);
printf ("\nLe lettere F o f sono:\t%d",f);
printf ("\nLe lettere G o g sono:\t%d",g);
printf ("\nLe lettere H o h sono:\t%d",h);
printf ("\nLe lettere I o i sono:\t%d",i);
printf ("\nLe lettere J o j sono:\t%d",j);
printf ("\nLe lettere K o k sono:\t%d",k);
printf ("\nLe lettere L o l sono:\t%d",l);
printf ("\nLe lettere M o m sono:\t%d",m);
printf ("\nLe lettere N o n sono:\t%d",n);
printf ("\nLe lettere O o o sono:\t%d",o);
printf ("\nLe lettere P o p sono:\t%d",p);
printf ("\nLe lettere Q o q sono:\t%d",q);
printf ("\nLe lettere R o r sono:\t%d",r);
printf ("\nLe lettere S o s sono:\t%d",s);
printf ("\nLe lettere T o t sono:\t%d",t);
printf ("\nLe lettere U o u sono:\t%d",u);
printf ("\nLe lettere V o v sono:\t%d",v);
printf ("\nLe lettere W o w sono:\t%d",w);
printf ("\nLe lettere X o x sono:\t%d",x);
printf ("\nLe lettere Y o y sono:\t%d",y);
printf ("\nLe lettere Z o z sono:\t%d",z);
    
    

    
    sleep (5);
    return(0);
}