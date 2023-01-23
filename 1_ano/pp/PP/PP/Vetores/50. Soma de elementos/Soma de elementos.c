#include <stdio.h>
#include <time.h>

int Vetor[5];

void Gera_Vetor()
{
	int i;
	
	// Preencher vetor
	
	for (i=0;i<5;i++)
	{
		Vetor[i] = 1+rand()%20;
	}
	
	// Mostrar vetor
	
	for (i=0;i<5;i++)
	{
		printf ("%d \t - \tPosicao : %d \n",Vetor[i],i);
	}
}

int Soma_Vetor ()
{
	int i,Count=0;
	for (i=1;i<5;i+=2)
	{
		Count += Vetor[i];
	}
	return Count;
}
main()
{
	int Total;
	srand(time(0));
	Gera_Vetor();
	Total=Soma_Vetor();
	printf ("\nTotal : %d numeros em posicoes impares",Total);
}
