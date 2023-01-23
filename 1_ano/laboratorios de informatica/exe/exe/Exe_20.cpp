

#include <stdio.h>
#include <stdlib.h>

float f(float x);

int main(void)
{

	float	a, b, dx, valor;

	printf("Introduza os limites do intervalo:\n");
	printf("Limite inferior: ");
	scanf("%f", &a);
	do {
		printf("Limite superior (> %.1f): ", a);
		scanf("%f", &b);
	} while (b <= a);
	do {
		printf("Introduza o incremento (<= %.1f): ", b - a);
		scanf("%f", &dx);
	} while (dx > b - a);

	do {
		valor = f(a);
		printf("f(%.1f)=%f\n", a, valor);
		a = a + dx;
	} while (a <= b);
}

float f(float x)
{
	float	res;

	res = 1.52 * x * x + 5;
	return(res);
}

