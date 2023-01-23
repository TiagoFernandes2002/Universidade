#include <stdio.h>
#include <stdlib.h>
#define N 10

void Lervetor(int *vetor, int n);
void Mostrarvetor(int *vetor, int n);

void main()
{
	int *V, n;
	
	printf("elementos do vetor: ");
	scanf("%d", &n);
	
	V = (int *)malloc(n*sizeof(int));
	
	if(V==NULL)
		exit(0);
	
	Lervetor(V, n);
	Mostrarvetor(V, n);
	
	free(V);
}

void Lervetor(int *vetor, int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf ("Insira o valor da %d posicao do vetor : ",i);
		scanf ("%d",&vetor[i]);
	}
}
void Mostrarvetor(int *vetor, int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf ("\n %d Posicao do vetor : %d \n",i,vetor[i]);
	}
}
