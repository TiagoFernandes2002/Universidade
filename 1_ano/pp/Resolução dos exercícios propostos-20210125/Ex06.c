/*
6. Implemente um programa que pe�a ao utilizador um nome completo, e o
escreva no ecr�. Considere um m�ximo de 20 carateres para o nome.
Exemplo: John Smith
*/

#include <stdio.h>

int main(void)
{
	char name[100];
	
	printf("Insert name: ");
	scanf("%[^\n]", name);

	printf("Name = %s\n", name);
	
	return 0;
}
