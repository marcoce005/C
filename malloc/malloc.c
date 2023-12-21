#include<stdio.h>
#include<stdlib.h>

int main(){
    int *testarr = malloc(5 * sizeof(int));
    testarr [0] = 1;
    testarr = malloc(6 * sizeof(6));
    testarr[5] = 5;
    printf("%i", testarr[5]);
}