

#include <stdio.h>
#include <stdlib.h>

#define HMS 60

int main()
{
    int t_dias, anos, semanas, dias;

    printf("Introduza os dias: ");
    scanf("%d", &t_dias);

    anos = t_dias / 365;
    t_dias = t_dias % 365;
    semanas = t_dias / 7;
    dias = t_dias % 7;

    printf("Anos: %d\n", anos);
    printf("Semanas: %d\n", semanas);
    printf("Dias: %d\n", dias);

	return 1;
}



