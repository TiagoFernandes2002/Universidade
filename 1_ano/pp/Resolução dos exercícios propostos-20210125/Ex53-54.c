/*
Exercicios 53 e 54
Este programa inclui os exercicios:
53. Implemente o algoritmo da ordenação por Seleção. 
54. Implemente o algoritmo da ordenação por Bolha.

Programa
- perguntar ao utilizador o tamanho do vetor
- criar dinamicamente um vetor de inteiros
- preencher o vetor com elemento aleatorios entre 0 a 100
- imprimir o vetor
- ordenar o vetor
- imprimir o vetor

Funções
- preencher um vetor com números aleatorios
- imprimir um vetor
- ordenar um vetor por seleção
- ordenar um vetor por bolha

Extras, funções para: 
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
	
	// leitura do número de elementos do vetor
	printf("Number of elements: ");
	scanf("%i",&nElem);
	
	// alocação dinamica de espaço para um vetor com nElem inteiros
	vector = (int*) malloc(nElem * sizeof(int));
	
	// preenchimento do vetor com números aleatórios
	randv(vector, nElem);
	
	// impressão do vetor de pois de ter sido preenchido 
	// com números aleatórios 
	printf("\nRandom vector: ");
	printv(vector, nElem);
	
	// impressão do vetor usando a função de impressão recursiva	
	printf("\nRecursion: ");
	printvr(vector, nElem);	
	
	printf("\n\nSorted: ");
	// chamada de uma das funções de ordenação implementadas (bubsort ou selsort)
	bubsortv(vector, nElem);
	
	// impressão do vetor ordenado
	printv(vector, nElem);	
	
	//liberta a memória alocada para o vetor
	free(vector);
	
}

/* 
Ordenação por seleção bolha (bubble sort)

Exº:
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
aleatórios entre 1 e 100
*/
void randv(int *v, int n){
	int i;
	
	srand(time(0));
	for( i=0; i<n; i++) v[i] = rand()%100+1;
}

/*
Imprime o conteúdo de um vetor de inteiros
*/
void printv(int *v, int n)
{
	int i;
	
	printf("\n[ ");  
	for(i=0; i<n; i++) printf("%i ", v[i]);
	printf("]\n");  
}

/*
Ordenação por seleção
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
