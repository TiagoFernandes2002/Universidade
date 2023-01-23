#include <stdio.h>

main()
{
	int i,Soma=0,Num;
	float A,B;
	
	printf ("Bem-Vindo !");
	
	
	for (i=1;i<=180;i++)
	{
		printf ("\nInsira o %d numero inteiro : ",i);
		scanf (" %f", &A);
		
		// Verificar se o nº é inteiro:
	
		B = (int)A;
		++B;
		
		if ((B-A)!=1)
		{
			printf ("\nO numero introduzido nao e inteiro !\n");
			i--;
		}
		else
		{
			printf ("\nO numero introduzido foi registado com sucesso !\n");
			Soma += A;
		}
	}
		printf ("Soma dos %d numeros introduzidos : %d",(i-1),Soma);
}
