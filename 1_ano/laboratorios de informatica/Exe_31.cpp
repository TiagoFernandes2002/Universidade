

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 30

typedef enum _STATUS { ERROR, OK }STATUS;

typedef struct _ALUNO
{
	char nome[MAX];
	int n_mec;
	float nota;
}ALUNO;

int LerAlunos(ALUNO** v, const char* filename);
STATUS ApRep(ALUNO* v, int size);

int main(void)
{
	ALUNO *v = NULL;
	int size;

	setlocale(LC_ALL, "Portuguese");
	switch(size=LerAlunos(&v,"alunos.txt"))
	{
	case -2: printf("\a\nErro na alocação de memória...\n");
		break;
	case -1: printf("\a\nErro de leitura do ficheiro...\n");
		break;
	case 0: printf("\a\nFicheiro vazio...\n");
		break;
	default: printf("Ficheiro de alunos lido com sucesso\n");
		if (ApRep(v, size))
			printf("Ficheiros criados com sucesso\n");
		else
			printf("ERRO na criação dos ficheiros\n");
	}

	return 1;
}

int LerAlunos(ALUNO ** v, const char* filename)
{
	FILE* fp;
	int size = 0;
	if ((fp = fopen(filename, "r")) == NULL)
		return -1;
	while (!feof(fp))
	{
		if ((*v = (ALUNO*)realloc(*v, sizeof(ALUNO) * (size + 1))) == NULL)
			return(-2);
		fscanf(fp, "%[^;];%d;%f\n", (*v + size)->nome , &((*v + size)->n_mec), &((*v + size)->nota));
		size++;
	}
	fclose(fp);

	return size;
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

