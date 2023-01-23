/*
7. O preço de um automóvel é calculado pela soma do preço de fábrica com o preço
dos impostos (45% do preço de fábrica) e a percentagem do revendedor (28%
do preço de fábrica). Implemente um programa que leia o nome do automóvel
e o preço de fábrica e que imprima o nome do automóvel e o preço final.
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
