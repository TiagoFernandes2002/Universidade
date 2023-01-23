#include <stdio.h>

int N=5;
int vetor(int *V, int N);

int main()
{
	int V[N];
	int i;
	for(i=0; i<N; i++)
	{
	printf("introduza um valor:");
	scanf("%d", &V[i]);
	}
	vetor(V, N);
}

int vetor(int *V, int N)
{
	int i;
	for(i=0; i<5; i++)
	{
		if(V[i] % 2 !=0)
			printf("%d, ", V[i]);
	}
	
}
