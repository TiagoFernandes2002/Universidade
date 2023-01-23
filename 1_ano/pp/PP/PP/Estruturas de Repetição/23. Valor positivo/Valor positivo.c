#include <stdio.h>

main()
{
	float NUM;
	
	do
	{
		printf ("Insira um valor positivo : ");
		scanf (" %f", &NUM);
		if (NUM>0)
		{
			printf ("O valor positivo introduzido e : %.1f",NUM);
		}
	}
	while (NUM<=0);
}
