/* 
escrever um programa que crie um vetor com valores aleatórios 
e calcule e imprima os elementos menor e maior
*/
 
#include <stdio.h>

/*
imprime um vetor
*/
void printv(int *p, int n)
{
	int i;
	
	for(i=0; i<n ; i++)
		printf("vetor[%i] = %i\n", i, p[i]);
}

/*
calcula e retorna através dos parametros mx e mn
os valores maior e menor dos elementos de um vetor
*/
void vmaxmin(int *v, int tamanho, int *mx, int *mn)
{
	int i, min, max;
	
	min = v[0];
	max = v[0];
	
	for(i=0; i<tamanho ; i++) {
		if(v[i]>max) max = v[i];
		if(v[i]<min) min = v[i];
	}
	
	*mx = max;
	*mn = min;
}

/* 
preenche o vetor com números aleatórios de 1 a 100
*/
void randv(int *p, int n)
{
	int i;
	
	for(i=0; i<n; i++) p[i] = rand()%100+1;
}

int main(void)
{
	int v[5] = {2, 5, 3, 7, 2};

	int max, min;
	
	randv(v, 5);
		
	printv(v,5);
	vmaxmin(v,5,&max,&min);
	printf("\nmax = %i; min = %i\n",max,min);
}
