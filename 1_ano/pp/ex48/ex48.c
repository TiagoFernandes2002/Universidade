#include <stdio.h>
#include <locale.h>

#define N 10

void main()
{
	int V[N];
	int i;
	setlocale(LC_ALL, "Portuguese");

	for(i=0; i<N; i++)
	{
		printf("introduza o valor %d:", i+1);
		scanf("%d", &V[i]);
	}
	for(i=0; i<N; i++)
	{
		printf("o valor %d é %d\n", i+1, V[i]);
	}
}
