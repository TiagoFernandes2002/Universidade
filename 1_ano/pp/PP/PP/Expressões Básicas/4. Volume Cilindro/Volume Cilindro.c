#include <stdio.h>

main()
{
	float Raio,Altura,Area_Base,Volume_Cilindro;
	
	printf ("Insira o valor (cm) do raio da base : ");
	scanf ("%f", &Raio);
	printf ("Insira o valor (cm) da altura do cilindro : ");
	scanf ("%f", &Altura);
	Area_Base = 3.14*Raio*Raio;
	Volume_Cilindro = Area_Base * Altura;
	printf ("O volume do cilindro de %.2f cm de raio e %.2f cm de altura e de : %.2f cm cubicos",Raio,Altura,Volume_Cilindro);
}
