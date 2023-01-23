

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Troca(int *a,int *b);

int main(void)
{
	int x,y;

	setlocale(LC_ALL, "Portuguese");
	printf("1º valor: ");
	scanf("%d", &x);
	printf("2º valor = ");
	scanf("%d", &y);

	printf("Originais: (%d:%d)\n", x, y);
	Troca(&x,&y);
	printf("Trocados: (%d:%d)\n", x, y);
	
	return 1;
}

void Troca(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

