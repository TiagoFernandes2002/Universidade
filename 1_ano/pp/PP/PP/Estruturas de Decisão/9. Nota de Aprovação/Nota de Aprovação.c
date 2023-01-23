#include <stdio.h>

main()
{
	float Nota;
	
	printf ("Bem-Vindo ! \n Insira a sua nota : ");
	scanf (" %f", &Nota);
	
	if (Nota >= 17.5)
	{
		printf ("Aprovado, Parabens !");
	}
	else if (Nota >= 9.5)
	{
		printf ("Aprovado !");
	}
	else
	{
		printf ("Reprovado !");
	}
}
