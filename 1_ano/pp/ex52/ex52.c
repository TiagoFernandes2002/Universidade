#include<stdio.h>


void main()
{
	char nomes[10][100];
	int i;
	
	for(i=0;i<10;i++)
	{
		printf("introduza o nome %d: ", i+1);
		gets(nomes[i]);
	}
	for(i=0;i<10;i++)
	printf("%s\n", nomes[i]);
}
