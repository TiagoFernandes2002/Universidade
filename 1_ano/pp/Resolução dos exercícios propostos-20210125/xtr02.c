/*
Imprima uma área retangular com lado inducado pelo utilizador e
preenchida com o carater '-'
*/

#include <stdio.h>

int main(void)
{
	int a, b, n;
	
	scanf("%i", &n);
	for(a=0; a<n; a++) {
		for(b=0; b<n; b++) {
			
			printf("-");
		}
		printf("\n");
	}
}
