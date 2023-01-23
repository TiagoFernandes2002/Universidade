

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define	M	10
#define	N	10

void ler_matriz(int V[M][N]);
void	escrever_matriz(int V[M][N]);
void	soma_linhas(int V[M][N]);
void	soma_colunas(int V[M][N]);

void main(void)
{
	int	V[M][N];

	ler_matriz(V);
	escrever_matriz(V);
	soma_linhas(V);
	soma_colunas(V);
}

void soma_linhas(int U[M][N])
{
	int	i, j, soma;

	for (i = 0; i < M; i++)
	{
		soma = 0;
		for (j = 0; j < N; j++)
			soma = soma + U[i][j];
		printf("Linha %d: %d\n",i,soma);
	}
	return;
}

void soma_colunas(int U[M][N])
{
	int	i, j, soma;

	for (j = 0; j < N; j++)
	{
		soma = 0;
		for (i = 0; i < M; i++)
			soma = soma + U[i][j];
		printf("Coluna %d: %d\n", j, soma);
	}
	return;
}

void ler_matriz(int U[M][N])
{
	int	i, j;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			printf("V[%d][%d]=", i, j);
			scanf("%d", &U[i][j]);
		}
	return;
}

void escrever_matriz(int U[M][N])
{
	int	i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%d\t",U[i][j]);
		printf("\n");
	}
	return;
}
