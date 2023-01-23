#include <stdio.h>

main()
{
	float Nota;
	
	printf ("Insira o valor da nota a ser avaliada :");
	scanf (" %f", &Nota);
	
	if (Nota>=0 && Nota<5)
	{
		printf ("\n Pessimo!");
	}
	else if (Nota>=5 && Nota < 8)
	{
		printf ("\n Mau!");
	}
	else if (Nota>=8 && Nota<10)
	{
		printf ("\n Insuficiente!");
	}
	else if (Nota>=10 && Nota<12)
	{
		printf ("1n Suficiente!");
	}
	else if (Nota>=12 && Nota<16)
	{
	printf ("\n Bom!");
	}
	else if (Nota>=16 && Nota<20)
	{
		printf ("\n Excelente!");
	}
	else 
	{
		printf ("\n Erro! Insira um valor valido!");
	}
}
