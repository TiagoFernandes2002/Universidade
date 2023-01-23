/*
4. Implemente um programa que calcule o volume (V) de um cilindro através dos
valores da altura (h) do cilindro e do raio (r) da base.
O volume do cilindro é dado por: V = h * PI * r ^ 2, com PI = p = 3.141592654.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.141592654

int main(void)
{
	float V, h, r;
	
	printf("Insert height (h): ");
	scanf("%f", &h);
	printf("Insert radius (r): ");
	scanf("%f", &r);
	
	V = h * PI * pow(r,2) ;
	printf("Volume = %f\n", V);
	
	return 0;
}
