#include <stdio.h>

main()
{
	int Total=1,i,B;
	float NUM;
	
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
		for (i=(B-1);i>0;i--)
		{
			Total *= i;
		}
		printf ("O fatorial de %d e = %d", B-1,Total);
	}
}
