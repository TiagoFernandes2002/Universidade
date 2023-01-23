/*

Guarda em ficheiro de texto o conteudo de um vetor descrevendo uma coleção de 3 automoveis
Exemplo de declaração de struct e uso de typedef

*/

#include <stdio.h>
#include <string.h>

typedef struct automovel {
	int ano;
	char modelo[10];
} AutoT;

int main(void)
{
	int i;
	FILE *fp;
	char fname[]="automoveis.txt";
	
	AutoT veiculo; // ou struct autom veiculo;
	AutoT coleAutos[3];
	
	coleAutos[0].ano=1973;
	strcpy(coleAutos[0].modelo, "Ford");
	coleAutos[1].ano=1979;
	strcpy(coleAutos[1].modelo, "Renault");
	coleAutos[2].ano=1985;
	strcpy(coleAutos[2].modelo, "Fiat");
	
	
	
	fp=fopen(fname,"w");
	if (fp==NULL) {
		printf("fopen error!\n");
		return 0;
	}
	
	for (i=0; i<3; i++) {

		fprintf(fp, "%i %s\n",coleAutos[i].ano, coleAutos[i].modelo);
	
		printf("ano: %i\n",coleAutos[i].ano);
		printf("modelo: %s\n",coleAutos[i].modelo);
	}	
	fclose(fp);
	
}
