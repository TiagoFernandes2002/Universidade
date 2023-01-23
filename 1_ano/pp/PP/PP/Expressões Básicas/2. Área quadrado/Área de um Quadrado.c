#include <stdio.h>

main()
{
	float Lado;
	
	printf ("Insira o valor do lado do quadrado : ");
	scanf (" %f", &Lado);
	printf ("O valor da area do quadrado de lado = %.2f, e de : %.2f ", Lado, (Lado*Lado));
}
