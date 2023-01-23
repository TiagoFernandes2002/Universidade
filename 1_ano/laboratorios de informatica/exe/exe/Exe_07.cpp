

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int	a = 3, b = 11, c = 2;
	float res;

	res = (float)(-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	printf("x = %.2f\n", res);
	res = (float)(-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	printf("y = %.2f\n", res);

    return 1;
}

