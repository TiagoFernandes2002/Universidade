/*
8. Uma empresa tem para um determinado funcionário uma ficha contendo o
nome, número de horas trabalhadas e o número de dependentes de um
funcionário. 
Considere que:
- A empresa paga 12 euros por hora e 40 euros por cada dependente.
- Sobre o salário são feitos descontos de 8,5% para o INSS e 5% para IRS.

Faça um algoritmo para ler o nome, o número de horas trabalhadas e o número
de dependentes de um funcionário. Após a leitura, escreva qual o nome, o salário
bruto, os valores descontados para cada tipo de imposto e finalmente qual o
salário líquido do funcionário.

*/

#include <stdio.h>
#define INSS_RATE 0.085
#define IRS_RATE 0.05
#define HOUR_PAY 12
#define DEP_PAY 40


int main(void)
{
	char funcName[100];
	int nHours, nDepend; 
	float grossSalary, netSalary, taxIrs, taxInss;

	
	printf("Insert name: ");
	scanf("%[^\n]", funcName);

	printf("Insert number of hours and number of dependents: ");
	scanf("%i %i", &nHours, &nDepend);
	
	grossSalary = nHours * HOUR_PAY + nDepend * DEP_PAY;
	taxInss = grossSalary * INSS_RATE;
	taxIrs = grossSalary * IRS_RATE;
	netSalary = grossSalary - taxInss - taxIrs;
	
	printf("\nName: %s\n", funcName);
	printf("Gross Salary = %.2f\n\n",grossSalary);
	printf("INSS tax = %.2f\n",taxInss);
	printf("IRS tax = %.2f\n\n",taxIrs);
	printf("Net Salary = %.2f\n\n",netSalary);
	
	
	return 0;
}
