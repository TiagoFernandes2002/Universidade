#include <stdio.h>

void main()
{
	char nome[20];
	int horas, dependentes, salariobruto;
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
	
	//escrita de dados
	printf("nome: %s\n", nome);
	printf("salario bruto: %d\n", salariobruto);
	printf("inss: %f\n", inss);
	printf("irs: %f\n", irs);
	printf("salario liquido: %f\n", salariobruto-irs-inss);
	
}
