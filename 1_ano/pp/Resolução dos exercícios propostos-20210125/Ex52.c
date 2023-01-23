/*
52. Crie um programa que armazene num vetor 10 nomes completos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10
#define M 100

void main(void)
{
	char nomes[N][M];
	int i;
	
	for(i = 0 ; i < N ; i++ ) 
	{
		printf("Name %d: ", i+1);
		gets(nomes[i]);
	}
	
	system("CLS");
	
	printf("Inserted names: \n");
	for(i = 0 ; i < N ; i++ ) 
	{
    	puts(nomes[i]);
	}
	
	system("pause");
}
