#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct _LIST_NODE
{
	void* data;
	struct _LIST_NODE* next;
} LIST_NODE;
typedef LIST_NODE* LIST;
typedef enum _BOOLEAN { FALSE = 0, TRUE = 1 } BOOLEAN;
typedef enum _LIST_LOCATION { LIST_START, LIST_END } LIST_LOCATION;
typedef enum _STATUS { OK, ERROR } STATUS;
typedef struct _ESTACAO {
	char desig[20];
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
STATUS InsertEnd(LIST* list, void* data);
int ListSize(LIST list);
void FreeList(LIST* list);
void ShowValues(LIST list);
STATUS ReadLine(LIST* list, const char* filename);
STATUS RemoveNode(LIST* list, void* DATA);
void* FindStationName(LIST list, char* STR);
void* LerEstacao();
STATUS Insert(LIST* lista, void* DATA);
STATUS InsertMid(LIST* list, void* data);
float CalculaPreco(LIST* list, char* ini, char end);
LIST_NODE* Existe(LIST list, char* str);
BOOLEAN ViagensValidas(LIST list, char* ini, char* end);




/****************************************************************
* Programa principal
***************************************************************/
int main()
{
	LIST list = NULL;
	void* ptr = NULL;

	/*if (ReadLine(&list, "linha1.txt") == OK)
	{
		ShowValues(list);
	}
	else
	{
		printf("Erro na leitura dos dados da linha\n");
	}*/
	int op;
	char aux;

	//if (ReadLine(&list, "linha1.txt")==OK)
	//{
		do {
			printf("1-Mostrar estacao\n");
			printf("2-Eliminar estacao\n");
			printf("3-Criar Esracao\n");
			printf("0- Sair\n");
			scanf("%d", &op);

			switch (op)
			{
			case 1:
				ShowValues(list);
				break;


			/*case 2:
			while((Getchar())!='\n')
				Get_s(STR);
			if((ptr = FindStationName(list, STR))!=NULL)
				RemoveNode(list, ptr);
				else
					printf("Erro\n");
				break;*/

			case 3:
				if((ptr = LerEstacao())!=NULL)
				{
					if (InsertIni(&list, ptr))
					{
						printf("Estacao adicionada!\n");
					}
					else
					{
						printf("Erro!\n");
					}
				}
					


				break;


			case 0:
				break;

			default:
				break;
			}

		} while (op);
			FreeList(&list);
		
	//}
	return 0;
}

STATUS ReadLine(LIST* list, const char* filename)
{
	FILE* fp = NULL;
	ESTACAO* pt = NULL;
	int ativa, no;

	if ((fp = fopen(filename, "r")) != NULL) {
		while (!feof(fp))
		{
			if ((pt = (ESTACAO*)malloc(sizeof(ESTACAO))) != NULL && (InsertIni(list, pt)) == OK) {
				fscanf(fp, "%[*;];%f;%d;%d;\n", pt->desig, &(pt->custo), &ativa, &no);
				pt->ativa = pt->no = FALSE;
				if (ativa)
					pt->ativa = TRUE;
				if (no)
					pt->no = TRUE;
			}
			else {
				//freeList(list);
				return ERROR;
			}
		}
		fclose(fp);
		return OK;
	}
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
* Funcao: verifica se a lista é vazia
*
* Parametros: list - apontador para lista
* Saida: TRUE se a lista for vazia, ERROR caso contrário
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
* Saida: OK se o nó foi inserido na LISTA e ERROR caso contrário
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
* Funcao: Insere um no' no fim da lista
*
* Parametros: list - apontador para lista
* (duplo apontador para o primeiro no')
* data - apontador generico para os dados a inserir no no' criado
* Saida: OK se o nó foi inserido na LISTA e ERROR caso contrário
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
	printf("LISTA ->");
	while (list != NULL)
	{
		printf("%f ->", ((ESTACAO*)DATA(list))->custo);
		list = NEXT(list);
	}
	printf(" FIM");
}

void FreeList(LIST* list) {
	LIST_NODE* node;
	while (*list != NULL)
	{
		node =  ( * list)->next;
		free(node->data);
		free(node);
	}
}

void * FindStationName(LIST list, char* STR) {
	while (list != NULL)
	{
		if (!strcmp(((ESTACAO*)list->data)->desig, STR))
			return list->data;
	}list = list->next;
	return NULL;
}

STATUS RemoveNode(LIST* list, void* DATA) {
	LIST_NODE* Temp = *list, * ANT = *list;
	while (Temp!=NULL)
	{
		if (Temp->data == DATA)
		{
			if (Temp = *list)
				*list = (*list)->next;
			else
			{
				ANT->next = Temp->next;
			}
			free(Temp->data);
			free(Temp);
		}return OK;

		ANT = Temp;
		Temp = Temp->next;

	}
	return OK;
}


void* LerEstacao()
{
	ESTACAO* ptr;
	char nome[20];

	if ((ptr = (ESTACAO*)malloc(sizeof(ESTACAO))) != NULL)
	{
		printf("Coloque o nome da sua estacao: ");
		while ((getchar()) != '\n');
			gets_s(nome);
	
		printf("coloque custo: ");
		scanf("%d", &(ptr->custo));

		strcpy(ptr->desig, nome);
		ptr->ativa = TRUE;
		ptr->no = FALSE;

		return ptr;

	}
	return NULL;

}

STATUS Insert(LIST* lista, void* DATA)
{
	int op;
	STATUS Flag = ERROR;

	printf("[1]- Inicio\n");
	printf("[2]- Meio\n");
	printf("[3]- Fim\n");

	scanf(" % d", &op);

	switch (op)
	{
	case 1:
		if (InsertIni(lista, DATA))
			Flag = OK;
		break;

	case 3:
		if (InsertEnd(lista, DATA))
			Flag = OK;
		break;

	case 2:
		if (InsertMid(lista, DATA))
			Flag = OK;
		break;
	default:
		printf("Erro");
		break;
	}
	return Flag;
}

STATUS InsertMid(LIST *list, void* data)
{
	LIST_NODE* new_node, * temp;
	char nome[20];
	printf("Coloque o nome da estacao anterior: ");
	while ((getchar()) != '\n');
	gets_s(nome);

	if (FindStationName(*list, nome) != NULL)
	{
		if ((new_node = NewNode(data)) != NULL)
		{
			/*while (strcmp(nome, ((ESTACAO)new_node->data)->desig)
			{
				new_node = new_node->next;
			
			new_node->
		}*/
			if (!strcmp(((ESTACAO*)(*list)->data)->desig, nome))
				*list = new_node;
			else
			{
				temp = *list;
				while (NEXT(temp) != NULL)
					temp = temp->next;
				NEXT(temp) = new_node;
			}
			return(OK);
		}
		return(ERROR);
	}
}

//STATUS Guardar(LIST list, const char * Filename)

float CalculaPreco(LIST list, char* ini, char* end)
{
	float custo = 0;
	if (ViagensValidas(list, ini, end))
	{
		while (strcmp(((ESTACAO*)list->data)->desig, ini))
			list = list->next;
		while (strcmp(((ESTACAO*)list->data)->desig, end))
		{
			custo += ((ESTACAO*)list->data)->custo;
			list = list->next;
		}
	}
	return custo;
}

LIST_NODE* Existe(LIST list, char* str)
{
	while (list!=NULL)
	{
		if (!strcmp(str, ((ESTACAO*)list->data)->desig))
			return list;

		list = list->next;
	}
	return NULL;
}


BOOLEAN ViagensValidas(LIST list, char* ini, char* end)
{
	LIST_NODE* node = NULL;

	if ((node = Existe(list, ini)) != NULL)
	{
		if (Existe(node->next, end) != NULL)
			return TRUE;
	}
	return FALSE;
}
