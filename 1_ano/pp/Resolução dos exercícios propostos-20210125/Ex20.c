/*
20. Implemente um programa que permita converter Km em Milhas. 
Se o número de Km for superior a 5000 deve também visualizar “muito longe”.
1 milha = 1609 metros
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	float km, miles;
	
	printf("Insert Km: ");
	scanf("%f",&km);
	
	miles = km / 1.609;
	
	printf("%.2f Km -> %.2f Miles\n", km, miles);
	if (km>5000) printf("Very far ...\n");
		
	return 0;
}
