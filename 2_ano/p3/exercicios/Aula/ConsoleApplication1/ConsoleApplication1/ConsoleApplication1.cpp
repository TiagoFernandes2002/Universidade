#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _LIST_NODE
{
	void* data;
	struct _LIST_NODE* next;
} LIST_NODE;

typedef LIST_NODE* LIST;
typedef enum _BOOLEAN { FALSE = 0, TRUE = 1 } BOOLEAN;
typedef enum _LIST_LOCATION { LIST_START, LIST_END } LIST_LOCATION;
typedef enum _STATUS { ERROR, OK } STATUS;

typedef struct _ESTACAO
{
	char desig[30];
	float custo;
	BOOLEAN ativa, no;
}ESTACAO;

#define DATA(node) ((node)->data)
#define NEXT(node) ((node)->next)
#define EMPTY NULL
#define NO_LINK NULL
void initList(LIST* list);
BOOLEAN emptyList(LIST list);
LIST_NODE* NewNode(void* data);
STATUS InsertIni(LIST* list, void* data);
STATUS InsertMeio(LIST* list, void* data);
STATUS InsertEnd(LIST* list, void* data);
int ListSize(LIST list);
void ShowValues(LIST list);
STATUS ReadLine(LIST* list, const char* filename);
void FreeList(LIST* list);
void* FindStation(LIST list, char* str);
void RemoveFirstNode(LIST* list);
STATUS RemoveNode(LIST* list, void* data);
STATUS Guardar(LIST* list, const char* Filename);
STATUS InsereEstacao(LIST* list);



/****************************************************************
* Programa principal
***************************************************************/
int main()
{
	LIST list = NULL;
	void* ptr = NULL;
	int op;
	char str[20];

	if (ReadLine(&list, "/Users/ricardoinacio/Desktop/UTAD/uni2ano/2semestre/algoritmia/pl/Linha1.txt"))
	{
		do
		{
			printf("1- Mostrar estacao \n");
			printf("2- Eliminar estacao \n");
			printf("3- Insere estacao \n");
			printf("4- Guardar lista \n");
			printf("0- sair \n");
			scanf("%d", &op);

			switch (op)
			{
			case 1: ShowValues(list);
				break;
			case 2:
				printf("Estacao: ");
				while ((getchar()) != '\n');
				gets(str);
				if ((ptr = FindStation(list, str)) != NULL)
				{
					RemoveNode(&list, ptr);
				}
				else
				{
					printf("Erro");
				}
				break;
			case 3:
				InsereEstacao(&list);
				break;
			case 4:
				Guardar(&list, "/Users/ricardoinacio/Desktop/UTAD/uni2ano/2semestre/algoritmia/pl/listaSaved.txt");
				break;
			case 0:
				exit(0);
				break;

			default: printf("Opcao Invalida");
			}

		} while (op);
		FreeList(&list);
	}

	else {
		printf("Erro");
	}


	return 0;
}

STATUS InsereEstacao(LIST* list) {
	char nome[20];
	int op, preco, ativa, no;
	ESTACAO* pt;
	printf("\nInsira o nome da estacao: ");
	while ((getchar()) != '\n');
	gets(nome);

	printf("\nInsira o preco da viagem: ");
	scanf("%d", &preco);

	if ((pt = (ESTACAO*)malloc(sizeof(ESTACAO))) != NULL)
	{
		do {
			printf("\n[1] - Inicio ");
			printf("\n[2] - Meio ");
			printf("\n[3] - Fim ");
			scanf("%d", &op);
		} while (op != 1 && op != 2 && op != 3);

		switch (op) {
		case 1:
			InsertIni(list, pt);
			break;
		case 2:
			InsertMeio(list, pt);
			break;
		case 3:
			InsertEnd(list, pt);
			break;
		default:
			printf("\nOpcao Invalida");
			break;
		}

		strcpy(pt->desig, nome);
		pt->custo = preco;
		pt->ativa = pt->no = TRUE;
		return OK;
	}

	return ERROR;

}

void RemoveFirstNode(LIST* list)
{
	LIST_NODE* node;

	while (*list != NULL)
	{
		node = *list;
		*list = (*list)->next;
		free(node->data);
		free(node);
	}
}

STATUS RemoveNode(LIST* list, void* data)
{
	LIST_NODE* tmp = *list, * ant = *list;

	while (tmp != NULL)
	{
		if (tmp->data == data)
		{
			if (tmp == *list)
			{
				*list = (*list)->next;
			}
			else
			{
				ant->next = tmp->next;
			}
			free(tmp->data);
			free(tmp);
			return OK;
		}
		ant = tmp;
		tmp = tmp->next;
	}
	return ERROR;
}

STATUS Guardar(LIST* list, const char* Filename)
{
	LIST pt;
	FILE* fp = NULL;
	int ativa, no;

	if ((pt = (LIST_NODE*)malloc(sizeof(LIST_NODE))) != NULL)
	{
		pt = *list;
		if ((fp = fopen(Filename, "w")) != NULL)
		{
			while (pt != NULL)
			{
				fprintf(fp, "%s;%.1f;%d;%d;\n", ((ESTACAO*)DATA(pt))->desig, ((ESTACAO*)DATA(pt))->custo, ((ESTACAO*)DATA(pt))->ativa, ((ESTACAO*)DATA(pt))->no);
				pt = NEXT(pt);
			}
		}
		free(pt);
		fclose(fp);
		printf("\nLista Guardada\n");
		return OK;
	}
	else {
		return ERROR;
	}

}


void FreeList(LIST* list)
{

	while (*list != NULL)
	{
		RemoveFirstNode(list);
	}

}


void* FindStation(LIST list, char* str)
{
	while (list != NULL)
	{
		if (!strcmp(((ESTACAO*)list->data)->desig, str))
		{
			return list->data;
		}
		list = list->next;
	}
	return NULL;
}

STATUS ReadLine(LIST* list, const char* filename)
{
	ESTACAO* pt;
	FILE* fp = NULL;
	int ativa, no;

	if ((fp = fopen(filename, "r")) != NULL)
	{
		while (!feof(fp))
		{
			if ((pt = (ESTACAO*)malloc(sizeof(ESTACAO))) != NULL && (InsertIni(list, pt)) == OK)
			{
				fscanf(fp, "%[^;];%f;%d;%d;\n", pt->desig, &(pt->custo), &ativa, &no);
				pt->ativa = pt->no = FALSE;
				if (ativa)
				{
					pt->ativa = TRUE;
				}
				if (no)
				{
					pt->no = TRUE;
				}
			}
			else
			{
				return ERROR;
			}
		}
		fclose(fp);
		return OK;
	}
	else
		return ERROR;

}

/****************************************************************
* Funcao: Inicializa a lista
*
* Parametros: list - apontador para lista
* (duplo apontador para o primeiro no')
* Saida: void
***************************************************************/

void initList(LIST* list)
{
	*list = NULL;
}

/****************************************************************
* Funcao: verifica se a lista � vazia
*
* Parametros: list - apontador para lista
* Saida: TRUE se a lista for vazia, ERROR caso contr�rio
***************************************************************/

BOOLEAN emptyList(LIST list)
{
	return (list == NULL) ? TRUE : FALSE;
}

/****************************************************************
* Funcao: Cria um no'
*
* Parametros: data - apontador generico para os dados a inserir no no' criado
* Saida: apontador para o no' criado ou NULL em caso de erro
***************************************************************/

LIST_NODE* NewNode(void* data)
{
	LIST_NODE* new_node;
	if ((new_node = (LIST_NODE*)malloc(sizeof(LIST_NODE))) != NULL)
	{
		DATA(new_node) = data;
		NEXT(new_node) = NULL;
	}
	return(new_node);
}

/****************************************************************
* Funcao: Insere um no' no inicio da lista
*
* Parametros: list - apontador para lista
* (duplo apontador para o primeiro no')
* data - apontador generico para os dados a inserir no no' criado
* Saida: OK se o n� foi inserido na LISTA e ERROR caso contr�rio
***************************************************************/

STATUS InsertIni(LIST* list, void* data)
{
	LIST_NODE* new_node;
	if ((new_node = NewNode(data)) != NULL)
	{
		NEXT(new_node) = *list;
		*list = new_node;
		return OK;
	}
	return ERROR;
}

/****************************************************************
* Funcao: Insere um no' no meio da lista
*
* Parametros: list - apontador para lista
* (duplo apontador para o primeiro no')
* data - apontador generico para os dados a inserir no no' criado
* Saida: OK se o n� foi inserido na LISTA e ERROR caso contr�rio
***************************************************************/

STATUS InsertMeio(LIST* list, void* data)
{
	char last[20];
	LIST_NODE* new_node;
	LIST node = *list;

	printf("\nInsira o nome da estacao: ");
	while ((getchar()) != '\n');
	gets(last);

	if ((new_node = NewNode(data)) != NULL)
	{
		if (FindStation(node, last) != NULL) {
			while (strcmp(last, ((ESTACAO*)DATA(node))->desig)) {
				node = NEXT(node);
			}
			NEXT(new_node) = NEXT(node);
			NEXT(node) = new_node;
			return OK;
		}
		else {
			return ERROR;
		}
		return OK;
	}
	return(ERROR);
}

/****************************************************************
* Funcao: Insere um no' no fim da lista
*
* Parametros: list - apontador para lista
* (duplo apontador para o primeiro no')
* data - apontador generico para os dados a inserir no no' criado
* Saida: OK se o n� foi inserido na LISTA e ERROR caso contr�rio
***************************************************************/

STATUS InsertEnd(LIST* list, void* data)
{
	LIST_NODE* new_node, * temp;
	if ((new_node = NewNode(data)) != NULL)
	{
		if (*list == NULL)
			*list = new_node;
		else
		{
			temp = *list;
			while (NEXT(temp) != NULL)
				temp = NEXT(temp);
			NEXT(temp) = new_node;
		}
		return(OK);
	}
	return(ERROR);
}

/***************************************************************************
* Funcao: calcula quantos elementos contem a lista
*
* Parametros: list - apontador para uma lista
* Saida: numero de elementos da lista
***************************************************************************/

int ListSize(LIST list)
{
	int count = 0;
	while (list != NULL)
	{
		count++;
		list = NEXT(list);
	}
	return count;
}
/****************************************************************
* Funcao: Escreve no ecra o conteudo da lista
*
* Parametros: list - apontador para o primeiro no'
* Saida: void
***************************************************************/

void ShowValues(LIST list)
{
	if (emptyList(list) == TRUE)
	{
		printf("\nLista vazia.\n");
		return;
	}
	printf("LISTA ->\n");
	while (list != NULL)
	{
		printf("%s -> \n", ((ESTACAO*)DATA(list))->desig);
		list = NEXT(list);
	}
	printf("\nFIM\n");
}