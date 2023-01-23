#include <stdio.h>

main()
{
	float Maior=0,NUM;
	while (NUM != -1)
	{
		printf ("Insira um numero : ");
		scanf (" %f", &NUM);
		
		if (NUM >= 0)
		{
			if (NUM>=Maior)
				Maior=NUM;
		}
		else
		NUM=-1;
	}
	printf ("O numero maior introduzido foi o : %.1f", Maior);
}
