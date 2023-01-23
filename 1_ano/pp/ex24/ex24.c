#include <stdio.h>
#include <locale.h>

int main()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	float valor, maximo;
	int contador;
	
	for (contador=1; contador<=50; contador ++)
	{
		printf("Coloque o seu %dº numero:", contador);
		scanf("%f", &valor);
		
		if(contador==1)
		{
			maximo = valor;
		}
		else
		{
			
			if(maximo<valor)
			maximo=valor;
		}
	}
	
	printf("valor máximo: %f", maximo);
}
