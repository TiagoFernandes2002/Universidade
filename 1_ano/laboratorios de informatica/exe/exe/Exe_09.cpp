

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
		printf("� simultaneamente divis�vel por 3 e por 5\n");
	else
		printf("N�o � simultaneamente divis�vel por 3 e por 5\n");



	return 1;
}

