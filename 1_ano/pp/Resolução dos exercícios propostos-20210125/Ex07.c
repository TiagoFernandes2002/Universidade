/*
7. O pre�o de um autom�vel � calculado pela soma do pre�o de f�brica com o pre�o
dos impostos (45% do pre�o de f�brica) e a percentagem do revendedor (28%
do pre�o de f�brica). Implemente um programa que leia o nome do autom�vel
e o pre�o de f�brica e que imprima o nome do autom�vel e o pre�o final.
*/

#include <stdio.h>
#define TAX_RATE 0.45
#define SALES_RATE 0.28


int main(void)
{
	char autoName[100];
	float factoryPrice, finalPrice;
	char aux;
	
	printf("Insert auto name: ");
	scanf("%[^\n]", autoName);

	printf("Insert factory price: ");
	scanf("%f", &factoryPrice);
	
	finalPrice = factoryPrice * (1 + TAX_RATE + SALES_RATE);
	
	printf("\nName = %s\nFactory price = %6.2f\nFinal price = %6.2f\n", autoName, factoryPrice, finalPrice);
	
	return 0;
}
