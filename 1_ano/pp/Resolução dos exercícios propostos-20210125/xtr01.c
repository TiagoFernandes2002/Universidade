/*
Imprimir n�meros aleat�rios no intervalo 
de 2 n�meros indicado pelo utilizador
*/

#include<stdio.h>
#include <time.h>

int main(void)
{

	int x,a,b;
	time_t t;	
	
	srand(time(&t));
	
	printf("intervalo de 2 n�meros: ");
	scanf("%i %i",&a,&b);
	
	while(1) {
		x = a+rand()%(b-a+1);
		printf("x = %i\n", x);
		sleep(1);
	}
}
