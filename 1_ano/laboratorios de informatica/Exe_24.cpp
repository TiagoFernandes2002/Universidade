

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 4

void LerVector(int*, int);
int Soma(int*, int);
float Media(int*, int);
int Maximo(int*, int);
int Minimo(int*, int);

int main(void)
{
	int v[N];

	setlocale(LC_ALL, "Portuguese");
	LerVector(v, N);
	printf("Soma: %d\n",Soma(v,N));
	printf("Média: %.2f\n", Media(v, N));
	printf("Máximo: %d\n", Maximo(v, N));
	printf("Mínimo: %d\n", Minimo(v, N));

	return 1;
}

void LerVector(int* v, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("v[%d]=", i);
		scanf("%d", &v[i]);
	}
}

int Soma(int* v, int size)
{
	int i,soma = 0;

	for (i = 0; i < size; i++)
		soma += v[i];
	return soma;
}

float Media(int* v, int size)
{
	return Soma(v,size)/(float)size;
}

int Maximo(int* v, int size)
{
	int i, max = v[0];

	for (i = 1; i < size; i++)
		if (v[i] > max)
			max = v[i];
	
	return max;
}

int Minimo(int* v, int size)
{
	int i, min = v[0];

	for (i = 1; i < size; i++)
		if (v[i] < min)
			min = v[i];

	return min;
}
