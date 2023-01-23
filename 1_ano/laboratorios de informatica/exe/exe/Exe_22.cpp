

#include <stdio.h>
#include <stdlib.h>

#define N 4

void LerVector(int*, int);
void MostrarVector(int*, int);

int main(void)
{
	int v[N];

	LerVector(v, N);
	MostrarVector(v, N);

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
void MostrarVector(int* v, int size)
{
	int i;

	for (i = size-1; i >= 0; i--)
		printf("v[%d]=%d\n", i, v[i]);
}

