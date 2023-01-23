#include <stdio.h>

main()
{
	int i,Total=0;
	
	for (i=0;i<=40;i+=2)
	{
		Total += i;
	}
	
	printf ("A soma dos 20 primeiros numeros pares e de: %d", Total);
}
