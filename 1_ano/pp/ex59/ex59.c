#include<stdio.h>
#include<stdlib.h>

void main()
{
	int numero, i;
	int *array, elemento= 0;
	do
	{
	
	printf("numeros:");
	scanf("%d", &numero);
	
	if(numero>=0)
		{
		elemento++;	
		
			if(array==NULL)
				array = malloc(sizeof(int*));
		
			else
				array =(int*)realloc(array, (elemento+1)*sizeof(int));
	
			array[elemento]=numero;
		}
	
	}
	while(numero!=-1);
	
	for(i=0;i<=elemento;i++)
		printf("%d", array[1]);
		
	free(array);
	
}

