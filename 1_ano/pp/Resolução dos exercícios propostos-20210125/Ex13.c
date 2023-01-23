/*
13. Implemente um programa que faça a classificação qualitativa de uma nota (valor
inteiro) de um aluno segundo os seguintes níveis:
  0 <= nota < 5: péssimo;
  5 <= nota < 8: mau;
  8 <= nota < 10: insuficiente;
  10 <= nota < 12: suficiente;
  12 <= nota < 16: bom;
  16 <= nota <= 20: excelente;


*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	float grade;
	
	printf("Grade (0..20): ");	
	scanf("%f", &grade);
	
	if (grade>=0 && grade<5) printf("péssimo\n");
	if (grade>=5 && grade<8) printf("mau\n");
	if (grade>=8 && grade<10) printf("insuficiente\n");
	if (grade>=10 && grade<12) printf("suficiente\n");
	if (grade>=12 && grade<16) printf("bom\n");
	if (grade>=16 && grade<20) printf("excelente\n");
			
	return 0;
}
