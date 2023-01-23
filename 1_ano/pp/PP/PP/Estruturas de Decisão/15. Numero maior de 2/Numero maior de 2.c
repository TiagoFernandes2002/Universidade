#include <stdio.h>

main()
{
	float A,B;
	
	printf ("Insira dois numeros (ex. 2 45) : ");
	scanf (" %f %f", &A,&B);
	if (A>B)
	{
		printf ("\n %.1f e maior do que %.1f !",A,B);
	}
	else if (B>A)
	{
		printf ("\n %.1f e maior do que %.1f !", B,A);
	}
	else
	{
		printf ("\n Erro! Insira 2 valores validos !");
	}
}
