#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double Adicao (double x, double y)
{
	return x+y;
}
double Subtracao (double x, double y)
{
	return x-y;
}
double Multiplicacao ( double x, double y)
{
	return x*y;
}
double Divisao (double x, double y)
{
	return x/y;
}
int Fatorial (int x)
{
	int i,Total=x;
	for (i=x-1;i>1;i--)
	{
		Total *= i;
	}
	return Total;
}
double Potencia (double x, double y)
{
	return pow(x,y);
}
int Digitos (double x)
{
	int z,count=0,aux;
	z=(int)x;
	do
	{
		z=z/10;
		count++;
	} while(z>=1);
	return count;
}
main()
{
	double aux,x,y;
	int a,b,c;
	double Total1,Total2,Total,Raiz;
	char OP;
	do
	{
		// Menu de opções
		
	printf ("\n");
	printf ("*****************");
	printf ("\n**             **");
	printf ("\n** CALCULADORA **\n");
	printf ("**             **\n");
	printf ("*****************\n \n");
	
	printf ("Escolha uma opcao : \n");
	printf ("(0) Adicao\n");
	printf ("(1) Subtracao\n");
	printf ("(2) Multiplicacao\n");
	printf ("(3) Divisao\n");
	printf ("(4) Fatorial\n");
	printf ("(5) Potencia\n");
	printf ("(6) Seno\n");
	printf ("(7) Cosseno\n");
	printf ("(8) Numero de digitos\n");
	printf ("(9) Raiz Quadrada\n");
	printf ("(R) Raiz de Polinomios\n");
	printf ("(E)Exit\n");
	scanf(" %c",&OP);
	
	// Adicao
	
	if (OP == '0')
	{
		printf ("Insira os valores do primeiro e segundo numero respetivamente : ");
		scanf (" %lf %lf",&x,&y);
		aux=Adicao(x,y);
		printf ("%.1lf + %.1lf = %.1f\n",x,y,aux);
		system ("pause");
	}
	
	// Subtracao
	
	else if (OP == '1')
	{
		printf ("Insira os valores do primeiro e segundo numero respetivamente : ");
		scanf (" %lf %lf",&x,&y);
		aux=Subtracao(x,y);
		printf ("%.1lf - %.1lf = %.1f\n",x,y,aux);
		system ("pause");
	}
	
	// Multiplicacao
	
	else if (OP == '2')
	{
		printf ("Insira os valores do primeiro e segundo numero respetivamente : ");
		scanf (" %lf %lf",&x,&y);
		aux=Multiplicacao(x,y);
		printf ("%.1lf * %.1lf = %.1f\n",x,y,aux);
		system ("pause");
	}
	
	// Divisao
	
	else if (OP == '3')
	{
		printf ("Insira os valores do primeiro e segundo numero respetivamente : ");
		scanf (" %lf %lf",&x,&y);
		aux=Divisao(x,y);
		printf ("%.1lf / %.1lf = %.1f\n",x,y,aux);
		system ("pause");
	}
	
	// Fatorial
	
	else if (OP == '4')
	{
		printf ("Insira o valor do numero : ");
		scanf (" %d",&a);
		Total=Fatorial(a);
		printf ("Fatorial de %d = %d\n",a,Total);
		system ("pause");
	}
	
	// Potencia
	
	else if (OP == '5')
	{
		printf ("Insira os valores da base e da potencia respetivamente : ");
		scanf (" %lf %lf",&x,&y);
		aux=Potencia(x,y);
		printf ("%.1lf^%.1lf = %.1lf\n",x,y,aux);
		system ("pause");
	}
	
	// Seno
	
	else if (OP == '6')
	{
		printf ("Insira o valor do numero : ");
		scanf (" %lf",&x);
		aux=sin(x);
		printf ("Seno de %.1lf = %.3lf\n",x,aux);
		system ("pause");
	}
	
	// Cosseno
	
	else if (OP == '7')
	{
		printf ("Insira o valor do numero : ");
		scanf (" %lf",&x);
		aux=cos(x);
		printf ("Seno de %.1lf = %.3lf\n",x,aux);
		system ("pause");
	}
	
	// Número de dígitos
	
	else if (OP == '8')
	{
		printf ("Insira o numero : ");
		scanf (" %lf",&x);
		Total = Digitos(x);
		printf ("Numero de Digitos : %d\n",Total);
		system ("pause");
	}
	
	// Raiz quadrada
	
	else if (OP == '9')
	{
		printf ("Insira o numero : ");
		scanf (" %lf",&x);
		aux = sqrt(x);
		printf ("Raiz Quadrada : %.1lf\n",aux);
		system("pause");
	}
	
	// Raiz Polinomial
	
	else if (OP == 'R' || OP == 'r')
	{
		printf ("Insira os valores de a,b e c respetivamente : ");
		scanf (" %d %d %d",&a,&b,&c);
		if (a==0)
		printf ("Erro! Valores incorretos ou solucao impossivel !");
		if (b*b == 4*a*c)
		printf ("Erro! Valores incorretos ou solucao impossivel !");
		else
		{
			Raiz = sqrt(((b*b)-(4*a*c)));
		
			// Fórmula completa:
			
			Total1 = ((-b)+Raiz)/(2*a);
			Total2 = ((-b)-Raiz)/(2*a);
			if (Total1 == Total2)
			printf ("Solucao : %.2lf", Total1);
			else if (Total1!=Total2)
			printf ("Possiveis solucoes : %lf e %lf\n",Total1, Total2);
			system ("pause");
		}
	}
	
	// Exit
	
	else if (OP == 'E' || OP == 'e')
	{
		printf ("O programa vai fechar! \n");
		exit(0);
	}
	
	// Default
	
	else
	{
		printf ("Erro! Insira ma opcao valida !");
		system ("pause");
	}
	}while(OP!='E' && OP!='e');
}
