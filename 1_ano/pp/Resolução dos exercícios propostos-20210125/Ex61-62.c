/* 
61. Escreva o c�digo de um programa que pe�a ao utilizador para introduzir uma
string e que apresente no ecr� a string escrita �ao contr�rio�.
Exemplo : �Universidade� deve ser escrito como �edadisrevinU�.

62. Escreva o c�digo de um programa que permita a introdu��o de uma string e que
escreva no ecr� a sigla representativa dessa string.
Exemplo : �World Wide Web� ? �WWW�. 
*/
#include<stdio.h>
#include<string.h>


int main(void)
{
	char name[100];
	int i, n, strLen, count=0;
	
	// l� uma string
	scanf("%[^\n]s",name);
	// imprime a string
	printf("\n\n%s\n\n", name);
	
	// calcula e imprime o tamanho da string
	strLen = strlen(name);
	printf("String length = %i\n",strLen);

	// imprime a string, imprimindo um carater de cada vez
	// ex�: "Ze Pedro"
	// 'Z','e',' ','P','e','d','r','o','\0'
	
	i=0;
	while(name[i]!='\0') {
		printf("%c",name[i]);
		i++;
	}
	
	// imprime a string "ao contr�rio"
	printf("\n\nInverted 1:\n");
	n = strlen(name);
	for(i=0; i<n; i++) printf("%c",name[n-i-1]);
	
	printf("\n\nInverted 2:\n");
	n = strlen(name);
	for(i=n-1; i>=0; i--) printf("%c",name[i]);
	
	// imprime as iniciais de cada palavra
	// "Ze manuel pedro" = Zmp
	printf("\n\nInits:\n");
	n = strlen(name);
	for(i=0; i<n; i++) {
		printf("%c",name[i]);
		while(name[i]!=' ' && name[i]!='\0') i++;
	} 
	
	// imprime as iniciais de cada palavra usando mai�sculas
	// "Ze manuel pedro" = ZMP
	printf("\n\nInits:\n");
	n = strlen(name);
	for(i=0; i<n; i++) {
		printf("%c",toupper(name[i]));
		while(name[i]!=' ' && name[i]!='\0') i++;
	} 
	
}

