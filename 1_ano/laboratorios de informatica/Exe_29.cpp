

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define	N	4
#define MAX 30

typedef enum _STATUS { ERROR, OK }STATUS;

typedef struct _ALUNO
{
	char nome[MAX];
	int n_mec;
	float nota;
}ALUNO;

STATUS LerAlunos(ALUNO* v, int size, const char* filename);
STATUS Aprovados(ALUNO* v, int size, const char* filename);
STATUS Reprovados(ALUNO* v, int size, const char* filename);
STATUS ApRep(ALUNO* v, int size);

int main(void)
{
	ALUNO v[N];

	setlocale(LC_ALL, "Portuguese");
	if (LerAlunos(v, N, "alunos.txt"))
	{
		if (ApRep(v, N))
			printf("Ficheiros criados com sucesso\n");
		else
			printf("ERRO na criação dos ficheiros\n");
/*
		printf("Ficheiro de alunos lido com sucesso\n");
		if (Aprovados(v, N, "aprovados.txt"))
		{
			printf("Ficheiro de aprovados criado com sucesso\n");
			if (Reprovados(v, N, "reprovados.txt"))
				printf("Ficheiro de reprovados criado com sucesso\n");
			else
				printf("ERRO na criação do ficheiro de reprovados\n");
		}
		else
			printf("ERRO na criação do ficheiro de aprovados\n");
*/	}
	else
		printf("ERRO na leitura do ficheiro de alunos\n");

	return 1;
}

STATUS LerAlunos(ALUNO * v, int size, const char* filename)
{
	FILE* fp;
	int i;
	if ((fp = fopen(filename, "r")) != NULL)
	{
		for (i = 0; i < size; i++)
			fscanf(fp, "%[^;];%d;%f\n", v[i].nome, &v[i].n_mec, &v[i].nota);
		fclose(fp);
		return OK;
	}
	else
		return ERROR;
}

STATUS Aprovados(ALUNO* v, int size, const char* filename)
{
	FILE* fp;
	int i;
	if ((fp = fopen(filename, "w")) != NULL)
	{
		for (i = 0; i < size; i++)
			if (v[i].nota >= 9.5)
				fprintf(fp,"%s;%d;%.2f\n", v[i].nome, v[i].n_mec, v[i].nota);
		fclose(fp);
		return OK;
	}
	else
		return ERROR;
}

STATUS Reprovados(ALUNO* v, int size, const char* filename)
{
	FILE* fp;
	int i;
	if ((fp = fopen(filename, "w")) != NULL)
	{
		for (i = 0; i < size; i++)
			if (v[i].nota < 9.5)
				fprintf(fp, "%s;%d;%.2f\n", v[i].nome, v[i].n_mec, v[i].nota);
		fclose(fp);
		return OK;
	}
	else
		return ERROR;
}

STATUS ApRep(ALUNO* v, int size)
{
	FILE* fpa, *fpr;
	int i;
	if (((fpa = fopen("aprovados.txt", "w")) != NULL) && ((fpr = fopen("reprovados.txt", "w")) != NULL))
	{
		for (i = 0; i < size; i++)
			if (v[i].nota >= 9.5)
				fprintf(fpa, "%s;%d;%.2f\n", v[i].nome, v[i].n_mec, v[i].nota);
			else
				fprintf(fpr, "%s;%d;%.2f\n", v[i].nome, v[i].n_mec, v[i].nota);
		fclose(fpa);
		fclose(fpr);
		return OK;
	}
	else
	{
		if (fpa != NULL)
			fclose(fpa);
		return ERROR;
	}
}

