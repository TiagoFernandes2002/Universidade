#include <stdio.h>

main()
{
	char OP;
	int m18=0,M18=0,Masculino=0,Feminino=0;
	float MediaIdadeM,MediaIdadem,MediaFeminino,MediaMasculino,i=1;
	
	for (i=1;i<=5;i++)
	{
		printf ("**************************\n");
		printf ("**                      **\n");
		printf ("**  Escolha uma opcao   **\n");
		printf ("**                      **\n");
		printf ("**************************\n \n");
		
		printf ("(1) Menos de 18 anos, sexo masculino\n");
		printf ("(2) Menos de 18 anos, sexo feminino\n");
		printf ("(3) Mais de 18 anos, sexo masculino\n");
		printf ("(4) Mais de 18 anos, sexo feminino\n");
		printf ("Opcao : ");
		scanf (" %c",&OP);
		
		if (OP == '1')
		{
			m18 += 1; 
			Masculino += 1;
			printf ("\n\n");
		}
		else if (OP == '2')
		{
			m18 += 1;
			Feminino += 1;
			printf ("\n\n");
		}
		else if (OP == '3')
		{
			M18 += 1;
			Masculino += 1;
			printf ("\n\n");
		}
		else if (OP == '4')
		{
			M18 += 1;
			Feminino += 1;
			printf ("\n\n");
		}
		else
		{
			printf ("Opcao incorreta !\n");
			i--;
			system("pause");
			printf ("\n\n");
		}
	}
	i=i-1;
	MediaIdadem = m18/i;
	MediaIdadeM = M18/i;
	MediaMasculino = Masculino/i;
	MediaFeminino = Feminino/i;
	//printf ("'%'");
	printf ("\n \n Medias: \n Menores de 18 anos : %.1f \n Maiores de 18 anos : %.1f \n Sexo Masculino %.1f \n Sexo Feminino %.1f",MediaIdadem,MediaIdadeM,MediaMasculino,MediaFeminino);
}
