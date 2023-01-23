#include <stdio.h>

main()
{
	float Lado;
	
	printf ("Insira o valor do lado do quadrado : ");
	scanf (" %f", &Lado);
	printf ("O valor do perimetro do quadrado de lado = %.2f e de : %.2f", Lado,(Lado*Lado));
}
