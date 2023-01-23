#include <stdio.h>

int Inserir (int i)
{
	int temp;
	
		printf ("Insira o %d numero inteiro: ",i);
		scanf (" %d",&temp);
		if (temp>=0 && temp<=20)
		return 1;
		else
		return 0;
}
main()
{
	int i,temp;
	for (i=1;i<=100;i++)
	{
		temp=Inserir(i);
		if (temp==0)
		{
		printf ("\nErro! Insira um valor inteiro entre 0 e 20!\n\n");
		i--;
		}
	}
}
