#include <stdio.h>

main()
{
	float A,B,C;
	
	printf ("Insira tres numeros (ex. 1 675 -34) : ");
	scanf (" %f %f %f",&A,&B,&C);
	
	if (A>B && A>C)
	{
		printf ("\n O numero %.1f e o maior de todos!", A);
	}
	else if (B>A && B>C)
	{
		printf ("\n O numero %.1f e o maior de todos!", B);
	}
	else if (C>A && C>B)
	{
		printf ("\n O numero %.1f e o maior de todos!", C);
	}
}
