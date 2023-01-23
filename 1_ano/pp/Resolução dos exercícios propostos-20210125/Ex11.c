/*
11. Implemente um programa que converta um par de valores (horas, minutos) do
formato 24 horas para o formato AM/PM.

Exemplo: 
13h07 -> 1h07 PM
00h25 -> 00h25 AM
12h21 -> 12h21 PM

*/

#include <stdio.h>

int main(void)
{
	int hour12, hour24, min;

	printf("Insert time 24h format (hours and minutes): ");
	scanf("%i %i", &hour24, &min);
	if(hour24>12) hour12=hour24-12; else hour12=hour24;
	
	printf("\n%02ih%02i -> %02ih%02i ", hour24,min,hour12,min);
	if(hour24<12) printf("AM\n"); else printf("PM\n");
		
	return 0;
}
