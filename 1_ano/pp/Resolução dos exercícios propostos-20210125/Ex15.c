/*
15. Implemente um programa que, de entre dois números fornecidos pelo utilizador,
permita encontrar o menor deles.

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	int num1, num2, smalest;
	
	scanf("%i %i",&num1, &num2);
	
	if (num1==num2) {
		printf("Equals!\n");
		return 0;
	}
	
	if (num1<num2) smalest=num1; else smalest=num2;
	printf("The smalest is %i\n", smalest);
			
	return 0;
}
