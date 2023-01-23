#include <stdio.h>
#include <string.h>
 
 int main()
 
 {
 	char nome[20], sobrenome[20];
 	char *nomecompleto;
 	
 	printf("introduza o nome:\n");
 	gets(nome);
 	printf("introduza o seu sobrenome:\n");
 	gets(sobrenome);
 	
 	nomecompleto=strcat(nome, sobrenome);
	
	printf("o seu nome é %s", nomecompleto);
 }
