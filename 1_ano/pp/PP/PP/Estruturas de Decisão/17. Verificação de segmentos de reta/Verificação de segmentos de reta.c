#include <stdio.h>

main()
{
	float S1,S2,S3;
	printf ("Insira o comprimento de 3 segmentos de reta (ex. 16 2 98) : ");
	scanf (" %f %f %f", &S1,&S2,&S3);
	
	if (S1+S2>S3 && S1+S3>S2 && S2+S3>S1)
	{
		printf ("\n Os lados formam um triangulo !");
	}
	else
	{
		printf ("\n Os lados nao formam um triangulo !");
	}
}
