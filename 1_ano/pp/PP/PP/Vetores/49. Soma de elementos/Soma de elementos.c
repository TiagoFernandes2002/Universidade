#include <stdio.h>
#include <time.h>

int Vetor[50];

void Gera_Vetor()
{
	int i;
	
	// Preencher vetor
	
	for (i=0;i<50;i++)
	{
		Vetor[i] = 1+rand()%50;
	}
	
	// Mostrar vetor
	
	for (i=0;i<50;i++)
	{
		printf ("%d \n",Vetor[i]);
	}
}

int Soma_Vetor ()
{
	int i,Count=0;
	for (i=0;i<50;i++)
	{
		if (Vetor[i]%2!=0)
		Count ++;
	}
	return Count;
}
main()
{
	int Total;
	srand(time(0));
	Gera_Vetor();
	Total=Soma_Vetor();
	printf ("\nTotal : %d numeros impares",Total);
}
