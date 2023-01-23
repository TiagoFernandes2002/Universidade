#include <stdio.h>

void main (void)
{
	int valor1, valor2, resultado;
	
	printf("introduz valor1");
	scanf("%d", &valor1);
	
	printf("introduz valor2");
	scanf("%d", &valor2);
	
	resultado = valor1 + valor2;
	
	printf("%d + %d = %d", valor1, valor2, resultado);
	
}
