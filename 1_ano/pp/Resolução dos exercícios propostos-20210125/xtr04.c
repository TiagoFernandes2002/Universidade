/*
Implemente um programa que calcule o maior e menor de 3 números reais inseridos pelo
utilizador. 
Implemente para o efeito uma função que calcule/retorne o maior e menor de
tred valores reais usando passagem de parametros por referência.
*/

#include<stdio.h>

void minMax(float, float, float, float *, float *);

void main(void)
{
	float a, b, c, min, max;
	
	scanf("%f%f%f",&a,&b,&c);
	
	minMax(a,b,c,&max,&min);
	
	printf("\n\n%f %f %f min = %f and max = %f\n", a,b,c,min,max);
	
}

void minMax(float x, float y, float z, float *mxp, float *mip)
{
	if(x>y && x>z) *mxp= x; 
	else if(y>z) *mxp=y; 
			else *mxp=z;
			
	if(x<y && x<z) *mip= x; 
	else if(y<z) *mip=y; 
			else *mip=z;
}


float maxNum(float x, float y)
{
	float bigger;
	
	if( x>y ) bigger=x; else bigger=y;
	
	return bigger;
	
}
