/*
28. Implemente um programa que permita efetuar 
a soma dos 180 primeiros números inteiros positivos.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void main(void) 
{ 
	int i, sum=0;
	
	for(i=1; i<=180; i++) {
		printf("%i + %i = ", sum, i);
		sum=sum+i;
		printf("%i\n", sum);
	}

	system("pause");
}
