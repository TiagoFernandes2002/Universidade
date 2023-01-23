#include <stdio.h>

void main()
{
	char nome[20];
	int horas, dependentes, salariobruto, opcao;
	float inss, irs;
	
	printf("nome:\n");
	gets(nome);
	
	printf("horas:\n");
	scanf("%d", &horas);
	
	printf("dependentes:\n");
	scanf("%d", &dependentes);
	
	// calculo
	salariobruto = horas *12 + dependentes * 40;
	inss= salariobruto * 0.085;
	irs= salariobruto*0.05;
	
	// menu de opções 
	 printf("******menu*******\n");
	 printf("1-nome\n");
	 printf("2-salario bruto\n");
	 printf("3-inss\n");
	 printf("4-irs\n");
	 printf("5-salario liquido\n");
	 printf("opcao:");
	 scanf("%d", &opcao);
	 
	 switch(opcao)
	 {
	 	case 1:
	 		printf("nome: %s\n", nome);
	 		break;
	 	case 2:
	 		printf("salario bruto: %d\n", salariobruto);
			break;
	 	case 3:
	 		printf("inss: %f\n", inss);
	 		break;
	 	case 4:
	 		printf("irs: %f\n", irs);
	 		break;
	 	case 5:
	 		printf("salario liquido: %f\n", salariobruto-irs-inss);
			break;
		default:
			printf("****valor invalido*****");
	 }
}
