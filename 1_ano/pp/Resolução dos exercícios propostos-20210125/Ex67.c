/*
67.	Implemente um programa que calcule todas as potências 
de base 2 até ao valor 32767, e armazene as mesmas num ficheiro ("pot2.txt").
*/
#include <stdio.h>
int main(void)
{
	FILE *fp;
	char c;
	int pot, npot;
	
	fp=fopen("pot2.txt","w");
	if (fp==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	pot=1;
	npot=0;
	do {
	 printf("2 ^ %i = %i\n",npot,pot);
	 fprintf(fp,"2 ^ %i = %i\n",npot,pot);
	 npot++;
	 pot*=2;
	} while (pot<32767);
	
	fclose(fp);
}
