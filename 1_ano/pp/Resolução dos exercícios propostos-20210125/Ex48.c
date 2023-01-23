/*
Considere um vetor V com Tamanho N preenchido com números inteiros.
48. Implemente um algoritmo que apresente no ecrã todos os elementos do vetor.
*/

#include<stdio.h>
#define N 5

void main(void)
{
	int i, num, vector[N];
	
	for(i=0; i<N; i++) {
		printf("enter vector[%i]: ", i);
		scanf("%i",&num);
		vector[i]=num;
	}
	
	printf("\n\nVector:\n");
	for(i=0; i<N; i++) {
		printf("vector[%i] = %i\n", i, vector[i]);
	}
	
	system("pause");
}
