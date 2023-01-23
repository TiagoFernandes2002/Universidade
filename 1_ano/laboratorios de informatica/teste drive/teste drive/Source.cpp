#include <stdio.h>
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "Portuguese");

	int contador, numero, pequeno;

	for (contador = 1; contador <= 5; contador++)
	{
		printf("Introduza o %dº valor inteiro:", contador);
		scanf_s("%d", &numero);

		if (numero < 0)
		{
			contador--;
		}
		if (contador == 1)
		{
			pequeno = numero;
		}
		else if (numero < pequeno)
		{
			pequeno = numero;
		}
	}
	printf("O menor numero é %d", pequeno);
}