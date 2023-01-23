/*
44. Implemente um programa que calcule o maior de 3 números reais 
inseridos pelo utilizador. 
Implemente para o efeito uma função que calcule/retorne o maior de
dois valores reais.
*/

#include <stdio.h>
#include <stdio.h>

float bigNumber(float x, float y);

int main() 
{
	float biggest, num1, num2, num3;
    
  	printf("insert 3 numbers: ");
   	scanf("%f%f%f", &num1, &num2, &num3);
	
	biggest = bigNumber(num1,num2);
	biggest = bigNumber(biggest,num3);
	
	printf("\nThe biggest is %f\n", biggest);

	system("pause");
    return 0;
}

float bigNumber(float x, float y)
{
	if (x>y) return x;
	else return y;
	
}
