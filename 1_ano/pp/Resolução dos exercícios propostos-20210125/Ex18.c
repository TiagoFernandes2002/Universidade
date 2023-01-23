/*
18. Implemente um programa que permita, através da inserção da dimensão dos
lados de um triângulo, identificar de que tipo de triângulo se trata. 
Considere apenas as seguintes situações:
	Isósceles - dois lados iguais e um diferente;
	Equilátero - todos os lados iguais;
	Escaleno - todos os lados diferentes.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int side1, side2, side3, biggest, a, b;
	
	/* Input sides of a triangle */
	printf("Enter three sides of a triangle: ");
	scanf("%i %i %i",&side1, &side2, &side3);
	
	if (side1==side2 && side2==side3) {
        /* If all sides are equal */
        printf("Equilateral triangle.");
    }
    else if (side1==side2 || side1==side3 || side2==side3) {
       		 /* If any two sides are equal */
        	printf("Isosceles triangle.");
			}
   		 else {
        		/* If none sides are equal */
      			  printf("Scalene triangle.");
    	}
			
	return 0;
}
