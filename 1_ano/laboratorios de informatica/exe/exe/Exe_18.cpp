

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	int num, fact, n;

	printf("introduza um inteiro positivo: ");
	scanf("%d", &num);

	fact = 1;
	n = num;

	if (n == 0)
		printf("Fatorial de %d = %d\n", num, fact);
	else
	{
		while (n != 0)
		{
			fact = fact * n;
			n = n - 1;
		}
		printf("%d! = %d\n", num, fact);
	}

	return 1;
}



