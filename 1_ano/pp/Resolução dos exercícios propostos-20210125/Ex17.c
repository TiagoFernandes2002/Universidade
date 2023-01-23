/*
17. Implemente um programa que permita, após a inserção de três valores
correspondentes a comprimentos de segmentos de reta, verificar se estes
podem formar um triângulo.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int num1, num2, num3, biggest, a, b;
	
	scanf("%i %i %i",&num1, &num2, &num3);
	
	if (num1==num2 && num1==num3) {
		printf("All numbers are equal!\n");
		return 0;
	}
	
	if (num1>num2) {
		biggest=num1;
		a=num2;
		b=num3;
	}
	else {
		biggest=num2;
		a=num1;
		b=num3;
	}
	if (num3>biggest) {
		biggest=num3;
		a=num1;
		b=num2;
	}
	
	if (biggest == sqrt(a*a+b*b)) printf("Right triangle (3-4-5)\n"); printf("Not a right T\n");
			
	return 0;
}
