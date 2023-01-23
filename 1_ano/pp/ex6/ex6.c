#include <stdio.h>

void main (void)
{
	float x, y;
	
	printf("escreva o valor do lado do quadrado este ira ser calculado pela consola\n ");
	scanf("%f", &x);
	
	y = x * x;
	printf("%f * %f = %f\n", x, x, y);
	
}

