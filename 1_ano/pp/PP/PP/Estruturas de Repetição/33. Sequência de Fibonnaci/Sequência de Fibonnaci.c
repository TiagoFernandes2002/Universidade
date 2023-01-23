#include <stdio.h>

main()
{
	float Temp;
	int B,NUM,i,T1=1,T2=1,Tn;
	
    printf ("Insira um numero inteiro : ");
	scanf (" %f", &Temp);
			
	// Verificar se o nº é inteiro:
				
	B = (int)Temp;
	++B;
	NUM=(B-1);
			
	if ((B-Temp)!=1)
		printf ("\nO numero introduzido nao e inteiro !\n");
	else
	{
    	printf("\n Sequencia de Fibonnaci : \n \n");

	    for (i = 1; i <= NUM; i++) 
		{
	        printf("%d  ", T1);
	        Tn = T1 + T2;
	        T1 = T2;
	        T2 = Tn;
	    }
	}
}
