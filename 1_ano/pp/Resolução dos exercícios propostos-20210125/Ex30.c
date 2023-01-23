/*
30. Implemente um programa que repita a mensagem “Introduza a Letra ‘a’” 
até que se verifique a sua inserção.
*/

#include <stdio.h>

void main(void) 
{ 
	char ch;
	
	do {
		printf("\nEnter character: ");
		//scanf("%c",&ch);
		// try ch=getchar() / ch=getch() / ch=getc(stdin) / scanf("%c",&ch);
		ch = getc(stdin);
		printf("Character: %c\n", ch);
	} while (ch!='a');
	
	printf("\nOK\n");
	
	system("pause");
}
