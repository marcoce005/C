#include<stdio.h>

struct N {
    double n1;
    double n2;
}n;

void print() {
    double tot = n.n1 + n.n2;
    printf("%.0lf\n", tot);

    if(n.n1 > n.n2) {
        n.n2 = tot;
    }
    else {
        n.n1 = tot;
    }
}

int main() {
    n.n1 = 0;
    n.n2 = 1;

    printf("%.0lf\n", n.n2);
    while (1)
    {
        print();
    }
    
    return 0;
}