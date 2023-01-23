/*
66.	Escreva o código de um programa que permita contabilizar 
o número de linhas de texto que estão armazenadas no ficheiro "dados.txt".
*/

#include <stdio.h>
int main(void)
{
	FILE *fp;
	char c;
	int count = 0;
	
	fp=fopen("message.txt","r");
	if (fp==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	while(!feof(fp)) {
		c=fgetc(fp);
		putchar(c);
		if (c=='\n') count++;
	}
	printf("\n\nthe file contains %i lines.\n",count);
	fclose(fp);
}
