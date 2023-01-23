

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define PI 3.14159

int Fatorial(int);
int Potencia(int, int);
int Soma(int, int);
int Subtracao(int, int);
int Multiplicacao(int, int);
float Divisao(int, int);
float Seno(int);
float Coseno(int);
int RaizQuad(int);

int main()
{
	int a, b, c;
	char op;

	setlocale(LC_ALL, "Portuguese");

	do {
		printf("O - Soma\n");
		printf("U - Subtração\n");
		printf("M - Multiplicação\n");
		printf("D - Divisão\n");
		printf("F - Factorial\n");
		printf("T - Potência\n");
		printf("E - Seno\n");
		printf("I - Co-Seno\n");
		printf("R - Raiz quadrada\n");
		printf("S - Sair\n");
		scanf("%c", &op);
		switch (op)
		{
		case 'o':
		case 'O': printf("operando 1: ");
			scanf("%d", &a);
			printf("operando 2: ");
			scanf("%d", &b);
			printf("Res: %d\n", Soma(a, b));
			break;
		case 'u':
		case 'U': printf("operando 1: ");
			scanf("%d", &a);
			printf("operando 2: ");
			scanf("%d", &b);
			printf("Res: %d\n", Subtracao(a, b));
			break;
		case 'm':
		case 'M': printf("operando 1: ");
			scanf("%d", &a);
			printf("operando 2: ");
			scanf("%d", &b);
			printf("Res: %d\n", Multiplicacao(a, b));
			break;
		case 'd':
		case 'D': printf("operando 1: ");
			scanf("%d", &a);
			printf("operando 2: ");
			scanf("%d", &b);
			if (b != 0)
				printf("Res: %.2f\n", Divisao(a, b));
			else
				printf("Operação Ilegal: divisão por 0\n");
			break;
		case 'f':
		case 'F': printf("numero: ");
			scanf("%d", &a);
			printf("Res: %d\n", Fatorial(a));
			break;
		case 't':
		case 'T': printf("base: ");
			scanf("%d", &a);
			printf("expoente: ");
			scanf("%d", &b);
			printf("Res: %d\n", Potencia(a, b));
			break;;
		case 'e':
		case 'E': printf("numero: ");
			scanf("%d", &a);
			printf("Res: %.2f\n", Seno(a));
			break;
		case 'i':
		case 'I': printf("numero: ");
			scanf("%d", &a);
			printf("Res: %.2f\n", Coseno(a));
			break;
		case 'r':
		case 'R': printf("numero: ");
			scanf("%d", &a);
			printf("Res: %d\n", RaizQuad(a));
			break;;
		case 's':
		case 'S': break;
		default: printf("Opcao invalida\n");
		}
		system("pause");
	} while (op != 'S' && op != 's');


	return 1;
}

int Fatorial(int x)
{
	int resultado = x;
	if (!x)
		return 1;
	while (x > 1)
		resultado *= --x;
	return resultado;
}

int Potencia(int x, int y)
{
	return pow((double)x, (double)y);
}

int Soma(int x, int y)
{
	return x + y;
}

int Subtracao(int x, int y)
{
	return x - y;
}

int Multiplicacao(int x, int y)
{
	return x * y;
}

float Divisao(int x, int y)
{
	return x / (float)y;
}

float Seno(int x)
{
	double rad;
	rad = PI * x / 180;
	return sin(rad);
}

float Coseno(int x)
{
	double rad;
	rad = PI * x / 180;
	return cos(rad);
}

int RaizQuad(int x)
{
	return sqrt((double)x);
}

