/*
Exercicios 53 e 54
Este programa inclui os exercicios:
53. Implemente o algoritmo da ordena��o por Sele��o. 
54. Implemente o algoritmo da ordena��o por Bolha.

Programa
- perguntar ao utilizador o tamanho do vetor
- criar dinamicamente um vetor de inteiros
- preencher o vetor com elemento aleatorios entre 0 a 100
- imprimir o vetor
- ordenar o vetor
- imprimir o vetor

Fun��es
- preencher um vetor com n�meros aleatorios
- imprimir um vetor
- ordenar um vetor por sele��o
- ordenar um vetor por bolha

Extras, fun��es para: 
- imprimir um vetor recursivamente
- preencher um vetor com 0s
*/

#include<stdio.h>
#include<stdlib.h>

void zerov(int *, int);
void randv(int *, int);
void printv(int *, int);
void selsortv(int *, int);
void bubsortv(int *, int);
void printvr(int *, int);

int main(void)
{
	int *vector;
	int nElem;
	
	// leitura do n�mero de elementos do vetor
	printf("Number of elements: ");
	scanf("%i",&nElem);
	
	// aloca��o dinamica de espa�o para um vetor com nElem inteiros
	vector = (int*) malloc(nElem * sizeof(int));
	
	// preenchimento do vetor com n�meros aleat�rios
	randv(vector, nElem);
	
	// impress�o do vetor de pois de ter sido preenchido 
	// com n�meros aleat�rios 
	printf("\nRandom vector: ");
	printv(vector, nElem);
	
	// impress�o do vetor usando a fun��o de impress�o recursiva	
	printf("\nRecursion: ");
	printvr(vector, nElem);	
	
	printf("\n\nSorted: ");
	// chamada de uma das fun��es de ordena��o implementadas (bubsort ou selsort)
	bubsortv(vector, nElem);
	
	// impress�o do vetor ordenado
	printv(vector, nElem);	
	
	//liberta a mem�ria alocada para o vetor
	free(vector);
	
}

/* 
Ordena��o por sele��o bolha (bubble sort)

Ex�:
8 elementos
1 20 21 16 9 15 26 24

0 a 7
1 20 16 9 15 21 24 26
1 16 9 15 20 21 24 26
1 9 15 16 20 21 24 26
1 9 15 16 20 21 24 26
*/
void bubsortv(int *v, int n)
{
	int i, temp, flag=1;
	
	while(flag==1) {
		flag = 0;
		for(i=0; i<n-1; i++) {	
			if(v[i+1]<v[i]) {
				flag = 1;
				temp = v[i+1];
				v[i+1]=v[i];
				v[i] = temp;	
			}
		}		
	}
}

/*
Preenche um vetor de inteiros com valores 
aleat�rios entre 1 e 100
*/
void randv(int *v, int n){
	int i;
	
	srand(time(0));
	for( i=0; i<n; i++) v[i] = rand()%100+1;
}

/*
Imprime o conte�do de um vetor de inteiros
*/
void printv(int *v, int n)
{
	int i;
	
	printf("\n[ ");  
	for(i=0; i<n; i++) printf("%i ", v[i]);
	printf("]\n");  
}

/*
Ordena��o por sele��o
*/
void selsortv(int *p, int n)
{
	int temp, imin,i,j;
	
	for (i=0; i<n; i++) {
		imin = i;
		for(j=i+1; j<n; j++) {
			if(p[j]<p[imin]) imin = j;
		}
		temp = p[i];
		p[i] = p[imin];
		p[imin] = temp;	
	}
}

/* 
Imprime o vetor usando recursividade
8 elementos
1 20 21 16 9 15 26 24
1

7 elementos
20 21 16 9 15 26 24
20

6 elementos
21 16 9 15 26 24
21

5 elementos
16 9 15 26 24
16

4 elementos
9 15 26 24
9

3 elementos
15 26 24
15

2 elementos
26 24
26

1 elementos
24
24

0 elementos
- return

*/
void printvr(int *v, int n)
{
	if(n==0) return;
	printf("%i ",v[0]);
	printvr(++v, --n);
}

/* 
Preenche o vetor com 0s
*/
void zerov(int *v, int n)
{
	int i;
	
	for(i=0; i<n; i++) v[i]=0;
}
