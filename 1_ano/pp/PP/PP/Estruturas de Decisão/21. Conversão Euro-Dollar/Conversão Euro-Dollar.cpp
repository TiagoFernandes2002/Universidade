#include <stdio.h>

main()
{
	float Conversao,Valor;
	char OP;
	printf ("Insira o tipo de moeda a converter : \n (D)Dollar \n (E)Euro \n");
	OP = getchar();
	switch (OP)
	{
		case 'E' :
		case 'e' : printf (" \n Qual o valor a converter ? "); scanf (" %f", &Valor);
		Conversao = Valor * 1.18; printf ("%.2f Euros equivalem a %.2f Dollars",Valor,Conversao);break;
		case 'D' :
		case 'd' : printf (" \n Qual o valor a converter ? "); scanf (" %f", &Valor);
		Conversao = Valor * 0.84; printf ("%.2f Dollars equivalem a %.2f Euros",Valor,Conversao);break;
		default : printf ("\n Erro ! Opcao incorreta ! ");
	}
}
