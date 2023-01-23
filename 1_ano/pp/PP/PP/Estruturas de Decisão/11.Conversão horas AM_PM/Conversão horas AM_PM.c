#include <stdio.h>

main()
{
	int Horas,Minutos,HorasPM;
	
	printf ("Insira uma hora (ex. hh mm ) : ");
	scanf (" %d %d",&Horas,&Minutos);
	if (Horas>12)
	{
			HorasPM = Horas - 12;
			printf ("%d %d pm", HorasPM,Minutos);
	}
	else if (Horas<=12)
	{
		printf ("%d %d am", Horas,Minutos);
	}
}
