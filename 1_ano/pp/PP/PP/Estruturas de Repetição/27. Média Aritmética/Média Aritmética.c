#include <stdio.h>

main()
{
	int i;
	float Nota,Total,Media;
	
	printf (" Intoduza a 1 nota : ");
	scanf (" %f", &Total);
	for (i=1;i<=19;i++)
	{
		printf ("\n Intoduza a %d nota : ",(i+1));
		scanf (" %f", &Nota);
		Total += Nota;
	}
	
	Media = Total/20;
	
	if (Media>20)
	{
		printf ("\n Media : 20 Valores");
	}
	else
	{
		printf ("\n Media : %.2f Valores",Media);
	}
}
