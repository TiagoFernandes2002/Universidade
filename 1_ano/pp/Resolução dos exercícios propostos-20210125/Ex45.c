/*
45. Implemente um programa que permita inserir uma sequência de 100 elementos
do tipo inteiro com valores entre 0 e 20. Utilize uma função que permita ao
utilizador inserir um valor inteiro apenas pode ter valor entre 0 e 20. Se tal não
acontecer deve insistir na leitura.
*/

#include <stdio.h>
#include <stdio.h>

int readNum(void);

void main(void)
{
	int a,num;
	
	for (a=0;a<100;a++) {
		num = readNum();
		printf("\nNum %i = %i\n", a,num);
	}
}

int readNum(void)
{
	int intN;
	do {
		printf("Insert a number (0..20): ");
		scanf("%i",&intN);
	} while(intN<0 || intN>20);
	return intN;
}
