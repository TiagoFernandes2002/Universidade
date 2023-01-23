#include <stdio.h>

int Vetor[5];

void Ler_Vetor()
{
	int i;
	for (i=0;i<5;i++)
	{
		printf ("Insira o valor da %d posicao do vetor : ",i);
		scanf ("%d",&Vetor[i]);
	}
}
void Mostrar_Vetor()
{
	int i;
	for (i=0;i<5;i++)
	{
		printf ("\n %d Posicao do vetor : %d \n",i,Vetor[i]);
	}
}
main()
{
	Ler_Vetor();
	Mostrar_Vetor();
}
