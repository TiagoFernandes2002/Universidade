/*
49. Implemente um algoritmo que calcule e apresente no ecrã a soma de todos os
elementos do vetor com valor ímpar.

50. Implemente um algoritmo que calcule e apresente no ecrã a soma de todos os
elementos do vetor que estejam numa posição de índice ímpar.
*/

#include<stdio.h>
#define N 5

void main(void)
{
	int i, sum, num, vector[N];
	
	// ler vetor de inteiros de tamanho N
	for(i=0; i<N; i++) {
		printf("Enter vector[%i]: ", i);
		scanf("%i",&num);
		vector[i]=num;
	}
	
	// imprimir vetor
	printf("\n\nVector:\n");
	for(i=0; i<N; i++) {
		printf("vector[%i] = %i\n", i, vector[i]);
	}
	
	// imprimir elementos do vetor com valor impar
	printf("\nOdd elements:\n");
	for(i=0; i<N; i++) {
		if (vector[i]%2 !=0) printf("vector[%i] = %i\n", i, vector[i]);
	}
	
	// soma dos elementos do vetor com valor impar 
	printf("\nSum of the odd elements:\n");
	sum=0;
	for(i=0; i<N; i++) {
		if (vector[i]%2 !=0) sum=sum+vector[i];
	}
	printf("Sum = %i\n", sum);
	
	// elementos do vetor com indice impar 
	printf("\nOdd index elements:\n");
	for(i=0; i<N; i++) {
		if (i%2 !=0) printf("vector[%i] = %i\n", i, vector[i]);		
	}
	
	// soma dos elementos do vetor com indice impar 
	printf("\nSum of the odd index elements:\n");
	sum=0;
	for(i=0; i<N; i++) {
		if (i%2 !=0) sum=sum+vector[i];
	}
	printf("Sum = %i\n", sum);
	
	system("pause");
}
