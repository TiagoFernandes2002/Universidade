
/*
Para fazer:
	- função que preencha elatoriamente o vetor meteo_leitura_diaria com valores plausiveis
	- função calcule a tempuratura minima e máxima do dia

*/


#include <stdio.h>

struct meteo {
	int dia;
	int hora;
	int pressao;
	int temp;
	int humid;
};

void print_leitura(struct meteo *mp);
int main(void)
{
	
	struct meteo meteo_leitura;
	
	struct meteo meteo_leitura_diaria[24];

	meteo_leitura.dia = 20;
	meteo_leitura.hora = 13;
	meteo_leitura.pressao=1024;
	meteo_leitura.temp=10;
	meteo_leitura.humid=70;
	print_leitura(&meteo_leitura);
}

void print_leitura(struct meteo *mp)
{
	printf("dia %i as %i: %iC, %imB %iperc\n", 
		mp->dia, 
		mp->hora, 
		mp->temp,	
		mp->pressao,
		mp->humid);
}
