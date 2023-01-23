#include <stdio.h>

main()
{
	float Total=0,Nota,Media;
	int Count=60,i;
	
	for (i=1;i<=60;i++)
	{
		printf ("Insira a %d nota (No caso de falta inserir 0) : ",i);
		scanf ( "%f",&Nota);
		if (Nota==0)
			Count--;
		Total += Nota;
		Nota = 0;
	}
	Media = Total/Count;
	printf ("A media total das notas inseridas e de : %.1f (%d Notas Inseridas)", Media,Count);
}
