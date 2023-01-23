#include <stdio.h>
#include <locale.h>


void main()
{
	int V[10]={11,22,33,44,55,66,77,88,99,100};
	int i, soma=0;
	setlocale(LC_ALL, "Portuguese");

	for(i=0; i<10; i++)
	{
		if(V[i] % 2 !=0)
			soma= soma + V[i];
			
	}
	printf("a soma dos ímpares é %d\n", soma);
}
