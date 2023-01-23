#include <stdio.h>

main()
{
	char Nome[21];
	printf ("Bem-Vindo ! \n Insira o seu nome completo (Max 20 caracteres) :");
	fgets (Nome,sizeof(Nome),stdin);
	printf ("O seu nome e : %s", Nome);
}
