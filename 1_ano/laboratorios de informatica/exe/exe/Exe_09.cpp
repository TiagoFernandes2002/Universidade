

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int x;

	setlocale(LC_ALL, "Portuguese");
	printf("Insira um inteiro:");
	scanf("%d", &x);


	if (x % 3 == 0 && x % 5 == 0)
		printf("É simultaneamente divisível por 3 e por 5\n");
	else
		printf("Não é simultaneamente divisível por 3 e por 5\n");



	return 1;
}

