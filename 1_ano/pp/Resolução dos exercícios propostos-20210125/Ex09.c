/*
9. Implemente um programa que pe�a ao utilizador uma nota de avalia��o
(num�rica) e que indique se o aluno est� APROVADO ou REPROVADO.
Nota: Este exerc�cio pode ser desenvolvido para outras situa��es como por exemplo ORAL.
*/

#include <stdio.h>

int main()
{
	float grade;
	
	/* insertion of the student's grade */
	printf("Insert the grade: ");
	scanf(" %f", &grade);
	/* presenting the result */
	if (grade >= 9.5) { // testing the approval conditon
		printf("The student was aproved!\n");
	}
	else {
		printf("The student was not aproved!\n");
	}
	system("pause");
	exit(0);
}

