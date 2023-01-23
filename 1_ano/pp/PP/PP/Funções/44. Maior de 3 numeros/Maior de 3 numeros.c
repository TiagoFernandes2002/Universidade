#include <stdio.h>

float Maior (float A, float B, float C)
{
	if (A>B && A>C)
		return A;
	else if (B>A && B>C)
		return B;
	else
		return C;
}
main()
{
	float A,B,C,M;
	printf ("Insira 3 numeros reais : ");
	scanf (" %f %f %f", &A,&B,&C);
	M = Maior(A,B,C);
	printf ("Maior : %.1f",M);
}
