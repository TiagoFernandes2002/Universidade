#include <stdio.h>

main()
{
	int i;
	float Num,temp,Maior=0;
	
	for (i=1;i<=50;i++)
	{
		printf ("Introduza um numero : ");
		scanf (" %f",&Num);
		if (Num>Maior)
		{
			Maior=Num;
		}
	}
	printf ("O maior numero introduzido foi o : %.1f", Maior);
}
