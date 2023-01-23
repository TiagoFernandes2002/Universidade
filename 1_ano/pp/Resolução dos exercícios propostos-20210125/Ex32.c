/*
32. Implemente um programa que verifique se um número é ou não primo.
*/

#include <stdio.h>

int main(void) 
{ 
    int num, i, flag_prime = 0;
    
	printf("enter a number: ");
	scanf("%i", &num);
	
	for(i=2; i<num/2; i++) {
		printf("\n%i\n",i);
		
		if (num % i == 0) {
            flag_prime = 1;
            break;
        }
	}
	if (num == 1) {
        printf("\n1 is neither prime nor composite.\n");
    }
    else {
        if (flag_prime == 0) printf("\n%d is a prime number.\n", num);
        else printf("\n%d is not a prime number.\n", num);
    }
	
	system("pause");
	return 0;
}
