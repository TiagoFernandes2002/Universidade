#include <stdio.h>

int main()
{
	float nota;
	
	printf("Introduza a nota:\n");
	scanf("%f", &nota);
	
	if (nota >= 9.5) 
	{
		printf("Aprovado\n");
	}
	else
	{
		printf("reprovado\n");
	}
}
