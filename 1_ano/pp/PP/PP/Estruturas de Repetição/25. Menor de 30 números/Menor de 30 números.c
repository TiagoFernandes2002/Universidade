#include <stdio.h>

main()
{
	int i;
	float Num,temp,Menor;
	
	printf ("Introduza um numero : ");
	scanf (" %f",&Menor);
		
	for (i=1;i<=29;i++)
	{
		printf ("Instroduza um numero : ");
		scanf (" %f",&Num);
		if (Num<Menor)
		{
			Menor=Num;
		}
	}
	printf ("O maior numero introduzido foi o : %.1f", Menor);
}
