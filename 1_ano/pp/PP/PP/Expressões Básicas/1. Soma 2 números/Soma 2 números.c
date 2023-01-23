#include <stdio.h>

main()
{
	float N1,N2;
	
	printf ("Insira dois numeros (ex: 2.3 6) : ");
	scanf ("%f %f", &N1,&N2);
	printf ("%.2f + %.2f = %.2f", N1,N2,(N1+N2));
}
