/*
31. Implemente um programa que permita calcular o fatorial 
de um número inteiro,tendo em conta que: n! = n*(n-1)!; com 0! = 1
Exemplo: 4! = 4*3*2*1* 0! = 24; 
*/

#include <stdio.h>

void main(void) 
{ 
	int n, num, fact=1;
	
	printf("enter a number: ");
	scanf("%i", &num);
	n=num;
	
	while (n>0) {
		fact = fact*n;
		n--;
	}
	
	printf("\n%i! = %i\n", num, fact);	
	
	system("pause");
}
