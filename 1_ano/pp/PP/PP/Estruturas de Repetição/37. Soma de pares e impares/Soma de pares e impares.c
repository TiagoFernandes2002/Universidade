#include <stdio.h>

main()
{
	int SomaPar=0,SomaImpar=0,NUM,i,B;
	float Temp;
	
	printf ("Insira um numero inteiro : ");
	scanf (" %f", &Temp);
			
	// Verificar se o nº é inteiro:
				
	B = (int)Temp;
	++B;
	NUM=(B-1);
			
	if ((B-Temp)!=1)
	{
		printf ("\nO numero introduzido nao e inteiro !\n");
	}
	else
	{
		for (i=1;i<=NUM;i++)
		{
			if (i%2==0)
				SomaPar += 1;
			else
				SomaImpar += 1;
		}
		printf ("Total numeros pares : %d \n Total numeros impares : %d",SomaPar,SomaImpar);
	}
}
