

#include<stdio.h>

int main(void)
{
	int m, n, i;
	long int res = 1;

	printf("introduza a base: ");
	scanf("%d", &m);
	printf("introduza o expoente: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		res *= m;

	printf("%d^%d = %d\n", m,n,res);

	return 1;
}



