/*
12. Implemente um programa que converta um valor em bytes para um formato
legível (Kilo, Mega, Giga ou Tera bytes consoante o múltiplo que melhor se
adapte a uma representação de fácil leitura do valor). 1024 bytes = 1Kbytes
Exemplo: 16548973 bytes = 15.78 MB

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	double valB, valKB, valMB, valGB;
	
	printf("unsigned long ULONG_MAX: %d Bytes : %lu\n", sizeof(long), ULONG_MAX);	
	printf("unsigned double DBL_MAX: %d Bytes : %f\n\n", sizeof(double), DBL_MAX);

	printf("Insert a number of bytes: ");
	scanf("%lf", &valB);
	
	printf("\n%.f Bytes = ", valB);
	
	if (valB < 1024) printf("%.2f Bytes\n",valB);
	else {
		valKB = valB/1024;
		if (valKB < 1024) printf("%.2f KB\n", valKB);
		else {
			valMB = valKB/1024;
			if (valMB<1014) printf("%.2f MB\n", valMB);
			else {
				valGB = valMB/1024;
				printf("%.2f GB\n", valGB);					
			}
		}
	}
		
	return 0;
}
