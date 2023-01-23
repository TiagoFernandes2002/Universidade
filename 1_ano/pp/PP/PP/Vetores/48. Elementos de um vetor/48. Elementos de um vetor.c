#include <stdio.h>
#include <time.h>

main()
{
	int Num,i;
	srand(time(0));
	Num = 1+rand()%50;
	int vetor[Num];
	//Preencher vetor
	for (i=1;i<=Num;i++)
	{
		vetor[i] = 1+rand()%50;
	}
	//Mostrar vetor
	for (i=1;i<=Num;i++)
	{
	printf ("%d \n",vetor[i]);
	}
}
