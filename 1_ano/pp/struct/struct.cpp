#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct atleta
	{
		char nome[20];
		int idade;
		int altura;
		int numero;
	};
	
int main()
{
	struct atleta atl;
	
	strcpy(atl.nome, "Rosa Mota");
	atl.idade=45;
	atl.altura=156;
	atl.numero=100;
	
	
	printf("Nome:");gets(atl.nome);
	printf("Idade:");scanf("%d", &atl.idade);
	printf("Altura:");scanf("%d", &atl.altura);
	printf("Numero:");scanf("%d", &atl.numero);
	
	printf("Nome:%s\n", atl.nome);
	printf("Idade:%d\n", atl.idade);
	printf("Altura:%d\n", atl.altura);
	printf("Numero:%d\n", atl.numero);
	
	
}
