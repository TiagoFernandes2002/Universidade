#include <stdio.h>

void main (void)
{
	char nome[20];
 	
 	printf("introduza nome completo (max 20 caracteres):\n");
 	gets(nome);
 	printf("%s", nome);
 	
}
