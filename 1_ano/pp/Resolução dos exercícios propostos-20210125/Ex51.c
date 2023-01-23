/*
51. Crie um programaque preencha um vetor V de N elementos do tipo inteiro. 
O programa deverá ter pelo menos os seguintes subprogramas:
a.LerVetor,
b.MostrarVetor.
*/

// Esta resolução contempla alocação dinâmica do vetor.

#include <stdio.h>
#include <stdlib.h>

void LerVetor(int *, int);
void MostrarVetor(int *, int);
int * CriarVetor(int);

void main(void)
{
	int *V, N;
	
	printf("Array size: ");
	scanf("%d", &N);
	
	V = CriarVetor(N);
	LerVetor(V, N);
	system("CLS");
	MostrarVetor(V, N);
	system("pause");
	free(V);
}

int * CriarVetor(int c)
{
	int *vect;
	vect = (int *) malloc(c * sizeof(int));
	return vect;
}

void LerVetor(int *vect, int c)
{
	int i;
	for(i = 0 ; i < c ; i++ ) 
	{
		printf("index [%d] = ", i);
		scanf("%d", &vect[i]);
	}
}

void MostrarVetor(int *vect, int c)
{
	int i;
	printf("Array values\n");
	for(i = 0 ; i < c ; i++ ) 
	{
    	printf("[%d] = %d \n", i, vect[i]);
	}
}
