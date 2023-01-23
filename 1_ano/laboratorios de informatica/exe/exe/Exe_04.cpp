

#include<stdio.h>
#include <stdlib.h>

#define HS 3600
#define KM 1000

int main()
{
	int	Kmh;
	float mseg;

	printf("Introduza os Km/h: ");
	scanf("%d", &Kmh);
	mseg = (float)Kmh * KM / HS;
	printf("%d Km/h = %.2f m/seg\n", Kmh, mseg);

    return 1;
}


