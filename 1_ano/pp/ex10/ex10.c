#include <stdio.h>
	
void main()
{
	float nota1, nota2, notafinal;
	
	printf("introduza a nota 1:");
	scanf("%f", &nota1);
	
	printf("introduza nota 2:");
	scanf("%f", &nota2);
	
	if (nota1 >= 8.5 & nota2 >= 8.5) 
	{
		notafinal= nota1*0.4 + nota2*0.6;
		
		if(notafinal>= 9,5)
		{
			printf("aprovado");
		}
		else
		{
			printf("reprovado");
		}
	}
	else
	{
		printf("reprovado");
	}
}
