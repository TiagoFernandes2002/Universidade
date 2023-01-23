/*
10. Elabore um algoritmo que permita calcular a nota M�dia de um aluno atendendo
�s notas obtidas nas duas Frequ�ncias e visualizar se foi aprovado ou reprovado,
tendo em conta que um aluno aprova sempre que a m�dia � superior ou igual a
9,5 valores.
O peso das frequ�ncias � de 40% para a 1� e 60% para a 2�. Para cada uma delas
� obrigat�ria uma nota m�nima de 8,5 valores, sem a qual o aluno est�
automaticamente reprovado.

*/

#include <stdio.h>

int main(void)
{

	float firstGrade, secondGrade, average;

	
	printf("Insert 1st and 2nd grades: ");
	scanf("%f %f", &firstGrade, &secondGrade);

	average = 0.4 * firstGrade + 0.6 * secondGrade;
	
	printf("\n1st grade = %f\n", firstGrade);
	printf("2nd grade = %f\n", secondGrade);
	printf("Average = %.2f\n\n", average);
	
	if ( (firstGrade < 8.5 ) || (secondGrade < 8.5) || (average < 9.5)) printf("FAIL\n"); else printf("APPROVED\n");
	
	return 0;
}
