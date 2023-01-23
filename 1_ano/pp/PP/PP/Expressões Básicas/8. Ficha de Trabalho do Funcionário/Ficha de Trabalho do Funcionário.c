#include <stdio.h>

main()
{
	char Nome[100];
	float Horas,Dependentes,Pagamento_Horas,Pagamento_Dependentes,IRS,INSS,Bruto,Liquido;
	
	printf ("Bem-Vindo ! \n \n Insira o seu Nome : ");
	fgets (Nome,sizeof(Nome),stdin);
	printf ("\n Insira o numero de Horas de trabalho : ");
	scanf (" %f", &Horas);
	printf ("\n Insira o numero de Dependentes :");
	scanf (" %f", &Dependentes);
	
	// Pagamento por Horas
	
	Pagamento_Horas = Horas * 12;
	
	// Pagamento por Dependentes
	
	Pagamento_Dependentes = Dependentes * 40;
	
	// Salario Bruto
	
	Bruto = Pagamento_Dependentes + Pagamento_Horas;
	
	// Descontos INSS
	
	INSS = Bruto*0.085;
	
	// Descontos IRS
	
	IRS = Bruto * 0.05;
	
	// Liquido
	
	Liquido = Bruto-IRS-INSS;
	
	printf ("\n \n Ficha de Trabalho : \n \n Nome : %s \n Horas de Trabalho : %0.1f \n Salario Bruto : %0.1f Euros \n Descontos INSS : %0.1f Euros \n Descontos IRS : %0.1f Euros \n",Nome,Horas,Bruto,INSS,IRS);
}
