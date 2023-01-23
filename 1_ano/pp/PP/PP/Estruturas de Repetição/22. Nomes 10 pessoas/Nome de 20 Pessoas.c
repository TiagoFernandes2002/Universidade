#include <stdio.h>

main()
{
	int i;
	char Nome[10][20];
	
	printf ("Bem-Vindo !");
	for (i=1;i<=10;i++)
	{
		printf ("\nInsira o seu nome completo (Max 20 caracteres) :");
		scanf (" %s",Nome[i]);
		printf ("%s", Nome[i]);
	}
}
