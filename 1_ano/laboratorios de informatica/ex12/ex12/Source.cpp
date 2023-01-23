#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int valor;

	printf("Coloque o ano pretendido:\n");
	scanf_s("%d", &valor);

	if( valor % 4 == 0){
		printf("Ano bissexto\n");
	}
	else {
		printf("Ano bastante normal\n");
	}
}