/*
Considere um vetor V com Tamanho N preenchido com números inteiros.
49. Implemente um algoritmo que calcule e apresente no ecrã a soma 
de todos os elementos do vetor com valor ímpar.
*/

// O preenchimento do vetor é feito recorrendo à função random numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void randomNumbers(int *, int);
void showArray(int *, int);
int sumOdd(int *, int);

void main(void)
{
	int V[N], sum;
	randomNumbers(V, N);
	showArray(V, N);
	sum = sumOdd(V, N);
	printf("The sum of the odd numbers of the array is %d. \n", sum);
	system("pause");
}

void randomNumbers(int *v, int size)
{
	int i;
	srand((int)time(NULL));
	for(i = 0 ; i < size ; i++ ) 
	{
		v[i] = rand()%10;
	}
}
void showArray(int *v, int size)
{
	int i;
	printf("Array values\n");
	for(i = 0 ; i < size ; i++ ) 
	{
    	printf("[%d] = %d \n", i, v[i]);
	}
}

int sumOdd(int *v, int size)
{
	int i, s = 0;
	for(i = 0 ; i < size ; i++ ) 
	{
		if (v[i] % 2 != 0){
			s += v[i];
		}
	}
	return s;
}
