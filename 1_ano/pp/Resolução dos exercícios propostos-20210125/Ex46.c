/*
46. Implemente um programa que permita efetuar somas entre dois números
fracionários. O resultado deverá ser apresentado no formato de fração. Utilize
funções para o máximo divisor comum e para o mínimo múltiplo comum.

*/

#include <stdio.h>
#include <stdio.h>

/* Greatest common divisor */
int gcd(int, int);
/* Lowest common multiple */
int lcm(int n1, int n2);

int main(void)
{
	int n, d, n1a, d1a, n2a, d2a, n1, d1, n2, d2, lcMult, gcDenom;
	
	printf("Enter two fraction numbers (ex: 2/3 3/4): ");
	scanf("%i/%i %i/%i",&n1,&d1,&n2,&d2);
	printf("\n%i/%i and %i/%i\n",n1,d1,n2,d2);
	
	lcMult = lcm(d1,d2);
	printf("lcm = %i; ",lcMult);

	n1a = n1*lcMult/d1;
	n2a = n2*lcMult/d2;
	n = n1a + n2a;
	d = lcMult;
	
	printf("%i/%i and %i/%i = %i/%i + %i/%i = %i/%i = ",
		n1,d1,n2,d2,n1a,lcMult,n2a,lcMult,n,lcMult);
		
	gcDenom = gcd(n,d);
	n = n / gcDenom;
	d = d / gcDenom;
	
	printf("%i/%i\n",n,d);
}

int gcd(int n1, int n2)
{
	while(n1!=n2)
    {
        if(n1 > n2) n1 -= n2; 
        else n2 -= n1;
    }   
    return n1;
}

int lcm(int n1, int n2)
{
	int max;
	max = (n1 > n2) ? n1 : n2;
    while (1) {
        if (max % n1 == 0 && max % n2 == 0) return max;
        ++max;
    }
}
