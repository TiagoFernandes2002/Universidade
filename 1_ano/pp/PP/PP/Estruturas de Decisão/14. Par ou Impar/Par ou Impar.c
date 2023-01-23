#include <stdio.h>

main()
{
	int NUM;
	
	printf ("Insira um numero inteiro :");
	scanf (" %d", &NUM);
	
	if (NUM%2==0)
	{
		printf ("\n O numero e par!");
	}
	else if (NUM%2!=0)
	{
		printf ("\n O numero e impar!");
	}
	else
	{
		printf ("Erro! Insira um valor valido!");
	}
}
