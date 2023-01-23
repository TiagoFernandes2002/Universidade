/*
24. Implemente um programa que permita encontrar 
o maior de 50 números inseridos pelo utilizador.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void main(void) 
{ 
	int i, num, bigger;
	int firstFlag=TRUE;
	
	for (i=0; i<50; i++) {
		printf("Insert a number(%i/50): ", i);
		scanf("%i", &num);
		if (firstFlag) {
			bigger=num;
			firstFlag=FALSE;
		} 
		else {
			if (num>bigger) bigger=num;
		}	
	}
	
	printf("\nThe biggest number is: %i\n", bigger);
	
	
	system("pause");
}
