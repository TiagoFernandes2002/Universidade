/*
5. Implemente um programa que pe�a ao utilizador os valores da base e da altura
de um tri�ngulo. Em seguida, apresente a �rea do mesmo.
Obs.: �rea = (Base * Altura) / 2
*/

#include <stdio.h>

int main(void)
{
	float area, base, height;
	
	printf("Insert base: ");
	scanf("%f", &base);
	printf("Insert height: ");
	scanf("%f", &height);
	
	area = (base * height) / 2;
	printf("Area = %f\n", area);
	
	return 0;
}
