#include <stdio.h>

main()
{
	int i;
	float Valor, Maior, Menor, Soma, Media;
	
	printf ("Insira o valor de precipitacao da localidade 1 : ");
	scanf (" %f",&Maior);
	Menor=Maior;
	Soma=Maior;
	
	for (i=2;i<=12;i++)
	{
		printf ("\n Insira o valor de precipitacao da localidade %d : ",i);
		scanf (" %f",&Valor);
		
		if (Valor>Maior)
			Maior = Valor;
		else if (Valor<Menor)
			Menor = Valor;
		Soma += Valor;
	}
	Media = Soma / (i-1);
	printf ("\n Valor Maximo : %.1f \n Valor Minimo : %.1f \n Media : %.1f", Maior,Menor,Media);
}
