#include <stdio.h>

main()
{
	float NUM,Total=0;
	int Count=0;
	
	while (NUM != -1)
	{
		printf ("Insira um numero : ");
		scanf (" %f", &NUM);
		Total += NUM;
		Count += 1;
	}
	printf ("Soma total : %.1f \n Numeros inseridos : %d", Total+1,Count-1);
}
