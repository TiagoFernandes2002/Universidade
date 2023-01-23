#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int a, b, c;
	
	printf ("Introduza 3 valores para os lados do triangulo\n");
	scanf("%d %d %d", &a, &b, &c);
	
	
	if (a+b>c || b+c>a || c+a>b){
	
	printf("triângulo");
}
		else
		{
		
			printf("não é triângulo");
}

	
}


