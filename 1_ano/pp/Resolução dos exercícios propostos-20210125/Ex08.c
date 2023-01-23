/*
8. Uma empresa tem para um determinado funcion�rio uma ficha contendo o
nome, n�mero de horas trabalhadas e o n�mero de dependentes de um
funcion�rio. 
Considere que:
- A empresa paga 12 euros por hora e 40 euros por cada dependente.
- Sobre o sal�rio s�o feitos descontos de 8,5% para o INSS e 5% para IRS.

Fa�a um algoritmo para ler o nome, o n�mero de horas trabalhadas e o n�mero
de dependentes de um funcion�rio. Ap�s a leitura, escreva qual o nome, o sal�rio
bruto, os valores descontados para cada tipo de imposto e finalmente qual o
sal�rio l�quido do funcion�rio.

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
