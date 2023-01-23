/*
68.	Implemente um programa converta todos os caracteres minúsculos, 
de um qualquer ficheiro de texto, em caracteres maiúsculos.
*/

#include <stdio.h>
int main(void)
{
	FILE *fp, *fdst;
	char c;
	char fname[] = "message.txt";
	char fnamedst[] = "caps.txt";
	
	fp=fopen(fname,"r");
	if (fp==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	fdst=fopen(fnamedst,"w");
	if (fdst==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	while(1) {
		c=fgetc(fp);
		if(feof(fp)) break;
		putchar(c);
		if (c>='a'&&c<='z') {
			putchar(c+'A'-'a');
			fputc(c+'A'-'a',fdst);
		}	
		else fputc(c,fdst);
	}
	fclose(fp);
	fclose(fdst);
}
