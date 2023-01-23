/*
69.	Implemente um programa que compare o conte�do de dois ficheiros 
e que indique no ecr� se os ficheiros s�o ou n�o iguais.
*/

#include<stdio.h>

int main(void)
{
	FILE *fo, *fd;
	char c1, c2;
	char forig[]="message.txt";
	char fdst[]="messagecopy.txt";
	int diff = 0;
		
	if ((fo=fopen(forig,"r"))==NULL) {
		printf("%s: fopen error!\n",forig);
		return 0;
	}
	if ((fd=fopen(fdst,"r"))==NULL) {
		printf("%s: fopen error!\n",fdst);
		return 0;
	}
	
	diff = 0;
	while(1) {
		c1=fgetc(fo);
		c2=fgetc(fd);
		printf("%c%c ",c1,c2);
		if (c1!=c2) {
			diff = 1;
			break;
		}	
		if(feof(fo) || feof(fd)) break;
	}
	
	fclose(fo);
	fclose(fd);
	
	if (diff==1) printf("Os ficheiros s�o diferentes!");
	else printf("Os ficheiros s�o iguais!");
	
}
