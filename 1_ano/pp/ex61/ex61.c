#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];
	int i;
	
	printf("introduza uma string: ");
	gets(string);
	
	printf("%s\n", string);
	
	for(i=strlen(string)-1;i>0;i--)
	{
		printf("%c",string[i]);
	}
}
