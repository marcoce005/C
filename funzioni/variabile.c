#include<stdio.h>

int v=2;

void f(int a)
{
    int v =4;
    printf ("\n\nNella funzione e':%d",v);
}
void main()
{
    printf ("\n\nNel main e':%d",v);

    int v=3;

    printf ("\n\nQui e':%d",v);   

    f(v);

}