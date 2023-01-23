#include <stdio.h>

main()
{
	float L1,L2,L3;
	
	printf ("Insira os lados de um triangulo : ");
	scanf (" %f %f %f",&L1,&L2,&L3);
	
	
	if (L1+L2>L3 && L1+L3>L2 && L2+L3>L1)
	{
		if (L1==L2 && L1==L3)
		{
			printf ("\n O triangulo e equilatero ! \n");
		}
		else if (L1==L2 || L1==L3)
		{
			printf ("O triangulo e isoceles ! \n");
		}
		else
		{
			printf ("O triangulo e escaleno ! \n");
		}
	}
	else
	{
		printf ("\n Os lados nao formam um triangulo !");
	}
	
}
