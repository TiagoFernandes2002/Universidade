

#include<stdio.h>
#include <math.h>

int main(void)
{
    int n = 0, soma = 0;

    do {
        n++;
        soma += n;
    } while (soma < 2000);

    printf("Soma = %d\n", soma - n);

    return 1;
}


