#include <stdio.h>

main()
{
	char OP;
	
	while (OP!='a' && OP!= 'A')
	{
		printf ("\n Introduza a letra 'a': ");
		scanf (" %c", &OP);
		
		if (OP=='a' || OP=='A')
		printf ("\n O programa vai fechar !");
	}
}
