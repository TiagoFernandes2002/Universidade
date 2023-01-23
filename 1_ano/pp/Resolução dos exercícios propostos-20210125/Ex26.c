/*
26. Implemente um programa que permita encontrar o maior e menor número 
de uma série de números positivos fornecidos.
A sequência termina com o número ‘0’.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void main(void) 
{ 
	int i, num, firstFlag=TRUE;
	int smallest, biggest;
	
	
	do {
		do {
			printf("Insert a number ('0' to exit): ");
			scanf("%i", &num);
		} while(num<0);
		
		if (firstFlag) {
			smallest=num;
			biggest=num;
			firstFlag=FALSE;
		} 
		else {
			if (num<smallest && num!=0) smallest=num;
			if (num>biggest && num!=0) biggest=num;
		}	
	} while(num!=0);
	
	printf("\nThe smallest number is: %i\n"
			"The biggest number is: %i\n", smallest, biggest);
	
	system("pause");
}
