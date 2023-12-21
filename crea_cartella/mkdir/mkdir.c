#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>

int main()
{
    char *nome = "Pippo";

    mkdir(nome, S_IRWXU);
    
    exit(EXIT_SUCCESS);

    return 0;
}