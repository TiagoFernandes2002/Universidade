#include <stdio.h>

main()
{
	float Num,Maior,Menor,NUM;
	
	printf ("Insira um numero : ");
	scanf (" %f", &NUM);
	if (NUM!=0)
	{
		Maior=NUM;
		Menor=NUM;
		do
		{
			printf ("Insira um numero : ");
			scanf (" %f", &Num);
			if (Num!=0)
			{
				if (Num<Menor)
				{
					Menor = Num;
				}
				else if (Num>Maior)
				{
					Maior = Num;
				}
			}
		}
		while (Num!=0);
		{
			printf ("\n A sequencia terminou pois o numero inserido foi o 0 ! \n O maior numero foi o : %0.1f \n O menor numero foi o : %.1f\n",Maior,Menor);
		}
	}
	else
	{
		printf ("\n O programa terminou pois o numero inserido foi o 0 !\n");
	}
}
