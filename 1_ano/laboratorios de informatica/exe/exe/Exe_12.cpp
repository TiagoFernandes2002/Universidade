

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int ano;

	setlocale(LC_ALL, "Portuguese");
	printf("Introduza o ano:");
	scanf("%d", &ano);

	if (ano < 1582)
		printf("Ainda vigorava o calend�rio Juliano\n");
	else
	{
		if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0))
			printf("Ano bissexto\n");
		else
			printf("Ano n�o bissexto\n");
	}

	return 1;
}


