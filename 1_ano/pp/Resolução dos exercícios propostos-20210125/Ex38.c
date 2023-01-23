/*
38. Implemente um programa que calcule a média de uma sequência, de valores reais, terminada por -1. 
O programa deve apresentar igualmente o número de valores introduzidos.
*/

#include <stdio.h>

int main(void) 
{
  	int num = 0;
	float val = 0, sum = 0, avg = 0;
	  
  	while(1) {
		printf("Insert a number: ");
  		scanf("%f", &val);
  		if(val==-1) break;
		num++;
		sum += val;
	}
	
    avg = sum/num;
    printf("The average of the %d numbers is %.2f.", num, avg);

	return 0;
}

