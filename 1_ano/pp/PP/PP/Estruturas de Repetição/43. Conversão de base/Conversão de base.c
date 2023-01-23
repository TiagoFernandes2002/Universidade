#include <stdio.h>

main()
{
	int Temp=0,RES=0,A,B,i=0,s,NUM[i];
	
	printf ("Insira um numero inteiro : ");
	scanf (" %d",&A);
	printf ("Insira a base do numero : ");
	scanf (" %d",&B);
	
	if (B>=1 && B<=10)
	{
		while (A>=1)
		{
			RES = A%B;
			A = (A/B);
			NUM[i] = RES;
			i++;
		}
		printf ("\n");
		for (s=i-1;s>=0;s--)
		{
			printf ("%d",NUM[s]);
		}
	}
	else
	{
		printf ("Erro! Base nao compreendida entre 0 e 10 !");
	}
}
