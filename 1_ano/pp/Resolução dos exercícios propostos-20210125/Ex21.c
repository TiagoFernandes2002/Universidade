/*
21. Implemente um programa que fa�a uma convers�o entre Euros e D�lares ou
vice-versa consoante a prefer�ncia do utilizador. O utilizador deve primeiro
escolher o tipo de convers�o e depois inserir o valor a converter.
1,00 � = 1,05 $
*/

#include <stdio.h>


int main(void)
{
	float money;
	char ch;
	
	printf("\n\nPress 'd' to converto Euros to Dollars, any other key to convert Dollars to Euros: ");
	scanf("%c", &ch);
	
	printf("Amount: ");
	scanf("%f",&money);
	
	if (ch=='d') printf("\n%.2f Euros -> %.2f Dollars", money, money*1.05);
	else printf("\n%.2f Dollars -> %.2f Euros", money, money/1.05);;
	
	return 0;
}
