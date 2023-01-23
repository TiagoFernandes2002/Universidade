#include <stdio.h>

int mmc (int x, int y)
{
	int i,s,Total;
	for (i=2;i<=(x*y);i++)
	{
		for (s=2;s<(x*y);s++)
		{
			if (y*s==x*i)
			{
				Total = x*i;
				return Total;
				break;
			}
		}
	}
}
int mdc (int x,int y)
{
	int i;
	if (x>y)
	{
		for (i=x;i>=1;i--)
		{
			if (x%i==0 && y%i==0)
			{
			return i;
			break;
			}
		}
	}
	else if (y>x)
	{
		for (i=y;i>=1;i--)
		{
			if (x%i==0 && y%i==0)
			{
			return i;
			break;
			}
		}
	}
}
main()
{
	
	int D1,D2,N1,N2,aux,Soma,AUX,MDC;
	printf ("Insira o numerador e denominador do 1 numero :");
	scanf (" %d %d",&N1,&D1);
	printf ("Insira o numerador e denominador do 2 numero :");
	scanf (" %d %d",&N2,&D2);
	// Caso tenha denominadores iguais
	
	if (D1==D2)
	{
		Soma=N1+N2;
		MDC=mdc(Soma,D2);
		Soma=Soma/MDC;
		D2=D2/MDC;
		printf ("A soma dos valores introduzidos e de: %d / %d",Soma,D2);
	}
	else if (D1!=D2)
	{
		AUX=D1;
		D1*=D2;
		N1*=D2;
		N2*=AUX;
		D2*=AUX;
		Soma=N1+N2;
		MDC=mdc(Soma,D2);
		Soma=Soma/MDC;
		D2=D2/MDC;
		printf ("A soma dos valores introduzidos e de: %d / %d",Soma,D2);
		
	}
}
