#include <stdio.h>

main()
{
	float Km,M,Milhas;
	
	printf ("Insira o numero de Km a converter : ");
	scanf (" %f", &Km);
	M = Km*1000;
	Milhas = M/1609;
	
	if (Km>=5000)
	{
		printf ("\n Muito longe ! \n Km : %.1f = Milhas : %.1f",Km,Milhas);
	}
	else
	{
		printf ("\n Muito longe ! \n Km : %.2f = Milhas : %.2f",Km,Milhas);
	}
}
