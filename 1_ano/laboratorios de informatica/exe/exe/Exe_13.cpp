

#include<stdio.h>

#define N 20

int main()
{
    int	i,count=0;
    float nota;
    
    for (i = 0; i < 20; i++)
    {
        printf("Introduza a nota do aluno %d: ", i+1);
        scanf("%f",&nota);
        if (nota >= 9.5)
            count++;
    }
    printf("Passaram %d alunos\n",count);

    return 1;
}


