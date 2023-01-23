/*
35. Implemente um programa que leia as notas de uma turma de 60 alunos numa
disciplina e calcule e apresente a média das notas. O professor pode apenas
inserir as notas dos alunos que entender, não sendo imperativo que haja a
inserção das 60 notas visto que certos alunos podem faltar ao Exame.
*/

#include <stdio.h>
#include <stdio.h>
#define N_GRADES 6

int main() 
{
	char ch;
    int i, count=0;
    int nGrade=N_GRADES;
	float average, grade, sum=0;
    
   for (i=1; i<=N_GRADES ; i++) {
   	printf("\nEnter the grade %i / %i (y or n)?: ", i,nGrade);
   	ch=getch();
   	
   	if (ch=='y') {
   		printf("Grade: ");
		scanf("%f", &grade);   	
   		sum =sum + grade;
   		count++;
		}
    
	}
	average = sum / count;
	printf("\nnumber of grades: %i\naverage: %f \n", count, average);
	
	system("pause");
    return 0;
}
