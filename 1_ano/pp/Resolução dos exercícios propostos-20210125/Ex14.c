/*
14. Implemente um programa que indique se um dado n�mero inteiro � PAR ou
IMPAR.

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	int num;
	
	if (1) printf("1 == True\n");
	if (0) printf("\n0 == True\n");
	
	scanf("%i",&num);
	
	if (num%2) printf("%d -> ODD",num); else printf("%d -> Even",num);
			
	return 0;
}
