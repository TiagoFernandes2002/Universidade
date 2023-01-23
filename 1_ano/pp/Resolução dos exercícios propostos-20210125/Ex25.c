/*
25. Implemente um programa que leia 30 números 
inteiros positivos e visualize o menor deles.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void main(void) 
{ 
	int i, num, smallest;
	int firstFlag=TRUE;
	
	for (i=0; i<30; i++) {
		do {
			printf("Insert a number(%i/30): ", i);
			scanf("%i", &num);
		} while(num<0);
		
		if (firstFlag) {
			smallest=num;
			firstFlag=FALSE;
		} 
		else {
			if (num<smallest) smallest=num;
		}	
	}
	
	printf("\nThe smallest number is: %i\n", smallest);
	
	system("pause");
}
