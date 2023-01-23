

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int hora, min, seg, cent, euro;

	setlocale(LC_ALL, "Portuguese");
	printf("Insira a duração no formato (h:m:s): ");
	scanf("%d:%d:%d", &hora, &min, &seg);

	
	if (seg > 0)
		min++; // min = min + 1;
	if (hora == 0)
		cent = min * 2;
	else if (hora <= 6)
		cent = 120 + (hora-1) * 60 + min;
	else
		cent = 120 + 6 * 60 + ((hora-7) * 60 + min) / 2;

	//ALERNATIVA 1
	float euros;
	euros = cent / 100.0;
	printf("Valor a pagar: %.2f euros\n", euros);

	//ALTERNATIVA 2
	euro = cent / 100;
	cent = cent % 100;
	printf("Valor a pagar: %d euros e %d cêntimos\n", euro, cent);

	return 1;
}
