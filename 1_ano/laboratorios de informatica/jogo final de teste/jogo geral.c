#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

#define LINE 13
#define COLUMN 13

int numero, num;

void prima()
{
	char tecla;
	printf("Eduardo Ribeiro\nTiago Fernandes");
	printf("\n\n\n\n                               !CANT STOP!\n\n\n");
	printf("                       Quem nao arrisca nao petisca!\n                       Quem tudo quer, tudo perde!\n\n\n\n");
	printf("                          (Prima qualquer tecla)\n\n\n\n\n");
	scanf("%c", &tecla);
	system("cls");
}
int name()
	{
		char nome[20];
			system("cls");
					printf("\n\n\n\n                        |NOME DO JOGADOR|\n\n\n\n");
					printf("NOME DO JOGADOR: ");
					scanf("%s", &nome);
					printf("%s\n\n\n\n", nome);
	}

int dice(void)
{
  int i, a;
  
  srand(time(NULL));
  
  for (i = 0; i < 4; i++)
  {
   a=(rand() % 5)+1;
   
    /* gerando valores aleatórios entre zero e 6 */
    printf("%d ", a);
  }
  
  getch();
  return 0;
}

int matrix_print(int matrix[][COLUMN],int i,int j)
{
	for(i=0;i<LINE;i++)
	{
		for(j=0;j<COLUMN;j++)
		if(matrix[i][j]!=0) printf(" %d ",matrix[i][j]);
		else printf("   ");
		
		printf("\n");
	}
	
	printf("\n\n\n");
}


int matrix_initialize(int matrix[][COLUMN],int i,int j)
{
	for(i=0;i<LINE;i++)
		for(j=0;j<COLUMN;j++)
			matrix[i][j]=0;
}

int matrix_fill(int matrix[][COLUMN],int i,int j)
{
	int aux=0;
	int index=0;
	
	for(j=0;j<COLUMN;j++)
	{
		aux=j+1;
		if(j>0 && j<7)
		{
			matrix[6][j]=aux;
			for(index=0;index<=j;index++) matrix[6-index][j]=aux;
			for(index=0;index<=j;index++) matrix[6+index][j]=aux;
		}
		
		if(j>=7 && j<12)
		{
			matrix[6][j]=aux;
			for(index=0;index<(13-j);index++) matrix[6-index][j]=aux;
			for(index=0;index<(13-j);index++) matrix[6+index][j]=aux;
		}

	}
}

int matrix_geral()
{
	int i=0,j=0;
	int matrix[LINE][COLUMN]; 
	//player p1={0,0},p2={2,1},p3={3,4};
	
	
	matrix_initialize(matrix,i,j);
	//matrix_print(matrix,i,j);

	matrix_fill(matrix,i,j);
	matrix_print(matrix,i,j);
}


	
		
int rules()
	{
		printf("\n                                  |TEMA|");
		printf("\n\n\n                  Jogo competitivo onde varios alpinistas\n");
		printf("                    procuram alcancar o topo da montanha.\n\n");
		printf("\n                                |OBJETIVO| \n\n");
		printf("                O objetivo do jogo e alcancar o topo da montanha\n");
		printf("               em tres pistas diferentes, no final do seu turno \n");
		printf("           (assinaladas por numeros de 2 ate 12) atraves da escalada\n");
		printf("                  das equipas de alpinistas de cada jogador. \n\n\n\n\n");
		printf("|VOLTAR|\n");
		printf("(clique 0)\n");
		scanf("%d", &numero);
				
				switch(numero)
				{
					case 0:
						system("cls");
						main();
						break;
				}
	}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char nome[20], nom[20];
	char tecla;
	prima();

	printf("\n\n\n\n                               !CANT STOP!\n\n\n");
	printf("\n-------------------------------|NOVO JOGO|--------------------------------------");
	printf("                                (clique 1)\n");
	printf("\n\n------------------------------|CARREGAR JOGO|-----------------------------------");
	printf("                                (clique 2)\n\n\n");
	printf("------------------------------|SOBRE O JOGO|------------------------------------");
	printf("                                 (clique 3)                                           \n");
	printf("\n----------------------------------|SAIR|----------------------------------------");
	printf("                                (clique 4)\n");
	scanf("%d", &numero);
	
	
	switch(numero)
	{
		case 1:
			name();
			matrix_geral();
			break;
			
		case 2:
			system("cls");
			/*printf("\n\n\n\n                              |CARREGAR O JOGO|\n\n");
			printf("JOGO 1...\n\n");
			printf("JOGO 2...\n\n");
			printf("JOGO 3...\n\n");
			
			printf("\n\n\n|VOLTAR|\n");
			printf("(clique 0)\n");
			scanf("%d", &numero);
		
				switch(numero)
					case 0:
					system("cls");
					main();
					break;
			
			switch(numero)
			{
				case 1:
					system("cls");
					
					break;
				
				case 2:
					system("cls");
					main();
					break;
					
			}
			system("pause");
			*/
			printf("EM MANUTENÇÃO!!!OK!!???MÁ LOGO \n\n");
			printf("Coloque 0 para voltar");
			scanf("%d", &numero);
				switch(numero)
					{
						case 0:
							system("cls");
							main();
							break;
					}
			break;
			
		case 3:
			system("cls");
			rules();
			break;
		case 4:
			system("cls");
			return printf("XAU!XAU!");
			break;
		
		default:
			system("cls");
			main();	
			break;
	}

}
