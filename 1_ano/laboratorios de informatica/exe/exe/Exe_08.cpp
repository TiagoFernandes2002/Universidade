

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;

	printf("Insira um inteiro:");
	scanf("%d", &x);
	if (x % 2 == 0)
		printf("Par\n");
	else
		printf("Impar\n");

	return 1;
}




