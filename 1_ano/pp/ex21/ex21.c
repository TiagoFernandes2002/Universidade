#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	float dolar, euro;
	do
	{
	
	printf("1-Euros------->Dolares\n");
	printf("2-Dolares------->Euros\n");
	printf("3-Sair\n");
	
	scanf("%d", &opcao);
	
	
	switch(opcao)
	{
	
	
	case 1:
	 		printf("introduza o valor em euros:\n");
	 		scanf("%f", &euro);
	 		dolar= euro/1.05;
	 		printf("Corresponde %f dólares\n", dolar);
	 		
	 		break;
	
	case 2:
	 		printf("introduza o valor em dólares:\n");
	 		scanf("%f", &dolar);
	 		euro= dolar*1.05;
	 		printf("Corresponde %f euros\n", euro);
	 		
	 		break;
	
 
 }
}while(opcao != 3)
}
