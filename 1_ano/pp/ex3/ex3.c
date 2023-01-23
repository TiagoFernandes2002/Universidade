#include <stdio.h>

void main(void)
{
	float x, y=4, z;
	
	printf("escreva quanto mede a lateral do quadrado em cm\n");
	scanf("%f", &x);
	
	z = x * y;
	
	printf("%f * %f = %f\n", x, y, z);
	printf("o seu retangulo tem de perimetro %f cm", z);
	
}
