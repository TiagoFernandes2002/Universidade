

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef enum _STATUS { ERROR, OK }STATUS;

#define	M	3
#define	N	3

STATUS 	ler_matriz(int V[M][N], const char* filename);
void	escrever_matriz(int V[M][N]);
void	soma_linhas(int V[M][N]);
void	soma_colunas(int V[M][N]);

int main(void)
{
	int	V[M][N];

	if (ler_matriz(V,"matriz.txt"))
	{
		escrever_matriz(V);
		soma_linhas(V);
		soma_colunas(V);
	}
	else
		printf("ERRO na leitura do ficheiro\n");

	return 1;
}

STATUS ler_matriz(int U[M][N], const char* filename)
{
	FILE* fp;
	int	i, j;

	if ((fp = fopen(filename, "r")) != NULL)
	{
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
				fscanf(fp,"%d ", &U[i][j]);
			fscanf(fp,"\n");
		}
		fclose(fp);
		return OK;
	}
	return ERROR;
}

void soma_linhas(int U[M][N])
{
	int	i, j, soma;

	for (i = 0; i < M; i++)
	{
		soma = 0;
		for (j = 0; j < N; j++)
			soma = soma + U[i][j];
		printf("Linha %d: %d\n", i, soma);
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

void escrever_matriz(int U[M][N])
{
	int	i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%d\t", U[i][j]);
		printf("\n");
	}
	return;
}


