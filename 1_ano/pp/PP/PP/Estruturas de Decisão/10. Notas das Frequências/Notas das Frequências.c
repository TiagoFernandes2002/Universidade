#include <stdio.h>

main()
{
	float N1,N2,Nota1,Nota2,Total;
	
	printf ("Insira as notas das frequencias (Primeira seguida da Segunda) (ex. 17 12.5) :");
	scanf (" %f %f",&N1,&N2);
	
	// Nota mínima de 8.5
	
	if (N1>8.4 && N2>8.4)
	{
	Nota1 = N1*0.40;
	Nota2 = N2*0.60;
	
	Total = (N1+N2)/2;
	
	printf ("\n Aluno aprovado com nota media de : %.2f", Total);
	}
	else
	{
		printf ("Reprovado! Pelo menos uma nota inferior a 8.5!");
	}
	
}
