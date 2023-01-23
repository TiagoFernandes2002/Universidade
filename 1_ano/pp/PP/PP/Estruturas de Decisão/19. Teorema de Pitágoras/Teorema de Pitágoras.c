#include <stdio.h>

main()
{
	float L1,L2,L3;
	
	printf ("Insira os lados de um triangulo : ");
	scanf (" %f %f %f",&L1,&L2,&L3);
	
	if (L1+L2>L3 && L1+L3>L2 && L2+L3>L1)
	{
		if (L3>L1 && L3>L2)
		{
			if ((L3*L3)==(L2*L2)+(L1*L1))
			{
				printf ("\n O triangulo e retangulo ! ");
			}
			else
			{
				printf ("\n O triangulo nao e retangulo ! ");
			}
			
		}
		else if (L2>L1 && L2>L3)
		{
			if ((L2*L2)==(L3*L3)+(L1*L1))
			{
				printf ("\n O triangulo e retangulo ! ");
			}
			else
			{
				printf ("\n O triangulo nao e retangulo ! ");
			}
		}
		else if (L1>L2 && L1>L3)
		{
			if ((L1*L1)==(L2*L2)+(L3*L3))
			{
				printf ("\n O triangulo e retangulo ! ");
			}
			else
			{
				printf ("\n O triangulo nao e retangulo ! ");
			}
		}
		else
		{
			printf ("\n O triangulo nao e ratangulo ! ");
		}
	}
	else
	{
		printf ("\n Erro ! Os lados nao formam um triangulo ! ");
	}
}
