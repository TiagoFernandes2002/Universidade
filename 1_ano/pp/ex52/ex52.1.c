#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	srand(time(NULL));
	printf("%d", aleatorio(5, 10));
}

int aleatorio(int min, int max)
{
	return min + (int) (rand()/(double) (RAND_MAX + 1) * (max- min+1));
}
