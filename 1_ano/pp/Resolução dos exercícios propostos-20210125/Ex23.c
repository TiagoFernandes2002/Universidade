/*
23. Implemente um programa que permita aceitar um valor num�rico 
que apenas pode ser positivo. 
Se n�o for positivo deve insistir na leitura.
*/

#include <stdio.h>

void main(void) 
{ 
	int num;
	
	do {
		printf("\nInsert a positive number: ");
		scanf("%i", &num);
	} while(num<0);
	
	printf("\nNumber: %i\n", num);
	
	system("pause");
}
