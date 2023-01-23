

#include <stdio.h>
#include <stdlib.h>

#define HMS 60

int main()
{
	int	h, m, seg;

	printf("Introduza as horas: ");
	scanf("%d", &h);
	printf("Introduza os minutos: ");
	scanf("%d", &m);
	seg = h * HMS * HMS + m * HMS;
	printf("%dh:%dmin = %d seg\n", h, m, seg);

	return 1;
}
