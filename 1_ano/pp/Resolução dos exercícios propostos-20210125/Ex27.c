/*
27. Dada uma s�rie de 20 valores reais, implemente um programa 
que calcule e escreva a m�dia aritm�tica destes valores. 
Entretanto se a m�dia obtida for maior que 20 
dever� ser atribu�do o valor 20 para a m�dia.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void main(void) 
{ 
	int i;
	float num, total=0, average;
	
	for (i=0; i<20;i++) {
		printf("\nInsert number (%i/20): ", i);
		scanf("%f", &num);
		total=total+num;
	}
	
	average = total/20;
	if (average>20) average=20;
	
	printf("\nAverage = %f\n", average);
		
	system("pause");
}
