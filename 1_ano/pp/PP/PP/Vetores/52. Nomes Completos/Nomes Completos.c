#include <stdio.h>

main()
{
	char Nome[10][50];
	
	int i;
	for (i=0;i<10;i++)
	{
		printf ("Insira o %d nome ",i+1);
		scanf(" %s", Nome[i]);
	}
	for (i=0;i<10;i++)
	{
		printf ("\n Nome : %s",Nome[i]);
	}
}
