/*
65.	Escreva o código de um programa que escreva 
no ficheiro "mensagem.txt" o texto "Olá mundo!".

*/
#include <stdio.h>

int main(void)
{
	
	FILE *fp;
	char str[1000];
	
	/* Abrir o ficheiro e escrever a mensagem com fprintf() */
	fp=fopen("message.txt","w");
	if (fp==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	fprintf(fp,"Hello world!\n");
	fclose(fp);
	
	/* Abrir o ficheiro e escrever a mensagem com fputs*/
	if ((fp=fopen("message.txt","a"))==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	fputs("Hello world again!\n", fp);
	fclose(fp);
	
	/* Abrir o ficheiro e ler a 1.a linha com fscanf()*/
	if ((fp=fopen("message.txt","r"))==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	fscanf(fp,"%[^\n]", str);
	printf("%s\n", str);	
	fclose(fp);
	
	/* Abrir o ficheiro e ler todas as linhas com fgets()*/
	if ((fp=fopen("message.txt","r"))==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	while (fgets(str, 1000, fp)!=NULL) puts(str);
	fclose(fp);
	
   
}
