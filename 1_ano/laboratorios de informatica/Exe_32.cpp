

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef enum _STATUS { ERROR, OK }STATUS;

STATUS	Dimensao(int* m, int* n, const char* filename);
STATUS	Alocacao(int ***V, int m, int n);
STATUS	ler_matriz(int **V, int m, int n,const char* filename);
void	escrever_matriz(int **V,int m,int n);
void	soma_linhas(int** V, int m, int n);
void	soma_colunas(int** V, int m, int n);

int main(void)
{
	int	**V=NULL,m,n;

	if (Dimensao(&m,&n,"matriz.txt"))
	{
		if (!Alocacao(&V, m, n))
		{
			printf("ERRO na alocação de memória\n");
			return 1;
		}
/*		if ((V = (int**)malloc(m * sizeof(int*))) != NULL)
		{
			for (int i = 0; i < m; ++i)
				if ((V[i] = (int*)malloc(n * sizeof(int))) == NULL)
				{
					printf("ERRO na alocação de memória\n");
					return 1;
				}
		}
		else
		{
			printf("ERRO na alocação de memória\n");
			return 1;
		}*/
		ler_matriz(V,m, n, "matriz.txt");
		escrever_matriz(V,m,n);
		soma_linhas(V,m,n);
		soma_colunas(V,m,n);
	}
	else
		printf("ERRO na leitura do ficheiro\n");

	return 1;
}

STATUS Dimensao(int *m, int *n, const char* filename)
{
	FILE* fp;
	char aux[50];

	*m = 0;
	*n = 0;
	if ((fp = fopen(filename, "r")) != NULL)
	{
		while (!feof(fp))
		{
			fgets(aux, sizeof(aux), fp);
			*n = *n + 1;
		}
		fclose(fp);
		*m = strlen(aux)/2;
		return OK;
	}
	return ERROR;
}

STATUS	Alocacao(int*** V, int m, int n)
{
	if ((*V = (int**)malloc(m * sizeof(int*))) != NULL)
	{
		for (int i = 0; i < m; ++i)
			if (((*V)[i] = (int*)malloc(n * sizeof(int))) == NULL)
				return ERROR;
	}
	else
		return ERROR;
	return OK;
}

STATUS ler_matriz(int **U, int m, int n,const char* filename)
{
	FILE* fp;
	int	i,j;
	char ch;

	if ((fp = fopen(filename, "r")) != NULL)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				fscanf(fp,"%d ", &U[i][j]);
			fscanf(fp,"\n");
		}
		fclose(fp);
		return OK;
	}
	return ERROR;
}

void soma_linhas(int** U, int m, int n)
{
	int	i, j, soma;

	for (i = 0; i < m; i++)
	{
		soma = 0;
		for (j = 0; j < n; j++)
			soma = soma + U[i][j];
		printf("Linha %d: %d\n", i, soma);
	}
	return;
}

void soma_colunas(int** U, int m, int n)
{
	int	i, j, soma;

	for (j = 0; j < n; j++)
	{
		soma = 0;
		for (i = 0; i < m; i++)
			soma = soma + U[i][j];
		printf("Coluna %d: %d\n", j, soma);
	}
	return;
}

void escrever_matriz(int** U, int m, int n)
{
	int	i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d\t", U[i][j]);
		printf("\n");
	}
	return;
}

