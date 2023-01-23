/*
22. Implemente um programa que permita aceitar 
e visualizar de seguida o nome de 20 pessoas. 
Considere um máximo de 20 carateres para o nome completo.
*/

#include <stdio.h>

#define MAX_NOME 50 
#define MAX_NOME_S "4"

void main(void) 
{ 
	char name[MAX_NOME] = ""; 
	// definition and initialization - empty 
	int i = 0;
	
	for (i = 1; i <= 20; i++) { 
	// cycle 20 rounds
		/* insertion of full name */ 
		printf("Insert the %d. name : ", i);
		
		//only allows chars between a-z and A-Z + spaces 
		//only reads a maximum of MAX_NAME_S chars 
		//if there are remaining chars they are kept in the buffer 
		scanf(" %" MAX_NOME_S "[a-zA-Z ]s", name); 
		// same as: scanf(" %49[a-zA-Z ]s", name);
		
		/* visualization of the inserted name */ 
		printf("It was inserted %s\n", name);
	} 
	system("pause");
}
