/*
66.	Escreva o c�digo de um programa que permita contabilizar 
o n�mero de linhas de texto que est�o armazenadas no ficheiro "dados.txt".
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
