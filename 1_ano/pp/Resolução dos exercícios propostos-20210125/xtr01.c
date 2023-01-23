/*
Imprimir números aleatórios no intervalo 
de 2 números indicado pelo utilizador
*/

#include<stdio.h>
#include <time.h>

int main(void)
{

	int x,a,b;
	time_t t;	
	
	srand(time(&t));
	
	printf("intervalo de 2 números: ");
	scanf("%i %i",&a,&b);
	
	while(1) {
		x = a+rand()%(b-a+1);
		printf("x = %i\n", x);
		sleep(1);
	}
}
