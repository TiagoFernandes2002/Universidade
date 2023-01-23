/*
5. Implemente um programa que peça ao utilizador os valores da base e da altura
de um triângulo. Em seguida, apresente a área do mesmo.
Obs.: Área = (Base * Altura) / 2
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
