#include <stdio.h>

void main()

{
	int valor;
	
	printf("introduza o valor:");
	scanf("%d", &valor);
	
	if (valor % 2 == 0) {
		printf("valor par");
	}
	else
	{
		printf("valor impar");
	}

}

