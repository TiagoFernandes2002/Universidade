#include <stdio.h>

main()
{
	float NUM;
	int i,B,Count=0;
	
	printf ("Insira um numero inteiro : ");
	scanf (" %f", &NUM);
			
	// Verificar se o nº é inteiro:
				
	B = (int)NUM;
	++B;
			
	if ((B-NUM)!=1)
	{
		printf ("\nO numero introduzido nao e inteiro !\n");
	}
	else
	{
		for (i=(B-2);i>1;i--)
		{
			if ((B-1)%i==0)
			{
				Count = 1;
			}
		}
		if (Count == 1)
			printf ("\n O numero nao e primo !");
		else
			printf ("\n O numero e primo !");
	}
}
