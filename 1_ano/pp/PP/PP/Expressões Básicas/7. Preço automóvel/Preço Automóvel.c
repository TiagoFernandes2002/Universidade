#include <stdio.h>

main()
{
	float Preco_Automovel,Preco_Fabrica, Imposto, Revendedor, Preco_Final;
	char Nome_Automovel[50];
	printf ("Bem-Vindo! \n Insira o nome do seu automovel : ");
	fgets(Nome_Automovel, sizeof(Nome_Automovel), stdin);
	printf ("\n Insira o preco de fabrica : ");
	scanf (" %f", &Preco_Fabrica);
	
	// Calculo Impostos
	
	Imposto = Preco_Fabrica*0.45;
	
	//Calculo % revendedor
	
	Revendedor = Preco_Fabrica * 0.28;
	
	// Preco Final
	
	Preco_Final = Preco_Fabrica+Imposto+Revendedor;
	
	printf ("\n O Carro : %s \n Preco de Fabrica : %.2f Euros \n \n Tem um valor final de : %.2f Euros", Nome_Automovel, Preco_Fabrica, Preco_Final);
}
