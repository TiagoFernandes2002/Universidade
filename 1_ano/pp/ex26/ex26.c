#include <stdio.h>
#include <locale.h>

int main()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	int tentativas, numero, maior, menor;
	
	tentativas=1;
	
	printf("coloque aqui o seu numero:");
	scanf("%d", &numero);
		
	while(numero != 0)
	{
		
		if(tentativas==1)
		{
			menor=numero;
			maior=numero;
		}
		else if(numero<menor && numero!=0)
		{
			menor=numero;
		}
		else if(numero>maior && numero!=0)
		{
			maior=numero;
		}
		tentativas++;
		
		printf("coloque aqui o seu %dº numero:", tentativas);
		scanf("%d", &numero);
		
	}
	if(numero == 0)
	{
	printf("o maior numero é: %d\n", maior);
	printf("o menor numero é: %d\n", menor);
	}
}
