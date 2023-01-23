/*
9. Implemente um programa que peça ao utilizador uma nota de avaliação
(numérica) e que indique se o aluno está APROVADO ou REPROVADO.
Nota: Este exercício pode ser desenvolvido para outras situações como por exemplo ORAL.
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

