/*
27. Dada uma série de 20 valores reais, implemente um programa 
que calcule e escreva a média aritmética destes valores. 
Entretanto se a média obtida for maior que 20 
deverá ser atribuído o valor 20 para a média.
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
