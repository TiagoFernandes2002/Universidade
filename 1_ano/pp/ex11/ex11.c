#include <stdio.h>

int main()
{
	
	int horas, minutos, pm;
	
	printf("Introduza a hora:\n");
	scanf("%d %d\n", &horas, &minutos);
	
	if (horas >12) 
	{
		pm = horas - 12;
		printf("%dh%d PM", pm, minutos);
	}
	
}


