/*
3. Implemente um programa que permita calcular o perímetro de um quadrado
*/

#include <stdio.h>

int main(void)
{
	int side, perimeter;
	
	printf("Insert side length: ");
	scanf("%i", &side);
	perimeter = 4 * side;
	printf("Perimeter = %i\n", perimeter);
	
	return 0;
}
