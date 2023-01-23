/*
16. Implemente um programa que, de entre três números fornecidos pelo utilizador,
permita encontrar o maior deles.
*/

#include <stdio.h>

int main(void)
{
	int num1, num2, num3, biggest;
	
	scanf("%i %i %i",&num1, &num2, &num3);
	
	if (num1==num2 && num1==num3) {
		printf("All numbers are equal!\n");
		return 0;
	}
	
	if (num1>num2) biggest=num1; else biggest=num2;
	if (num3>biggest) biggest=num3;
	
	printf("The biggest number is %i", biggest);
			
	return 0;
}
