/*
29. Implemente um programa que permita calcular a soma 
dos 20 primeiros números pares positivos.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void main(void) 
{ 
	int num=2, sum=0, count=1;
	
	while(num!=0) {
		printf("%i -> %i + %i = ", count, sum, num);
		sum = sum+num;
		printf("%i\n",sum);
		num = num+2;
		count = count+1;
		
		if (count>20) num=0;		
	}
	
	system("pause");
}
