/*
33. Implemente um programa que, dado um n�mero natural n, 
apresente no ecr� os n primeiros n�meros da sequ�ncia de Fibonacci.
*/

#include <stdio.h>
#include <stdio.h>

int main(void) {
	
    int i, n, t1 = 0, t2 = 1, nextTerm;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
