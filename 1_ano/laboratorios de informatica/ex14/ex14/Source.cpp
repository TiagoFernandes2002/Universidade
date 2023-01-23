#include <stdio.h>

int main()
{

	int n, contador, m, total=1;

	printf("coloque a base da potencia:\n");
	scanf_s("%d", &m);
	printf("coloque o seu expoente:\n");
	scanf_s("%d", &n);

	for(contador = 1; contador <= n; contador++)
	{
		total = total * m;
	}

	printf("o seu numero: %d", total);
}