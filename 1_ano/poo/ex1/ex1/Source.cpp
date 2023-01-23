#include <stdio.h>
#include <stdlib.h>
using namespace std;
main()
{
	FILE* f1, * f2;
	int a, b;
	// abre o ficheiro dados_ent.txt no modo de leitura e associa-o a f1
	if ((f1 = fopen("dados_ent.txt", "r")) == NULL) {
		printf("ERRO: não é possível abrir o ficheiro dados_ent.txt\n");
		exit(1);
	}

	// abre o ficheiro dados_saida.txt no modo de escrita e associa-o a f2
	if ((f2 = fopen("dados_saida.txt", "w")) == NULL) {
		printf("ERRO: não é possível abrir o ficheiro dados_saida.txt\n");
		exit(1);
	}
	fscanf(f1, "%d", &a); // leitura e escrita
	fscanf(f1, "%d", &b);
	printf("%d %d\n", a, b);
	fprintf(f2, "Este ficheiro foi alterado na aula Nº .\n");
	fprintf(f2, "%d\n", a * a);
	fprintf(f2, "%d\n", b * b);
	fclose(f1); // fecha o ficheiro associado a f1
	fclose(f2); // fecha o ficheiro associado a f2
	system("pause");
	return 0;
}