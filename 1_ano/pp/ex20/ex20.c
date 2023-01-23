#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	
	float milha, km;
	
	printf("Ponha os km`s:\n");
	scanf("%f", &km);
	
	milha = km/ 1.609;
	
	if(km > 5000){
	
		printf("Muito longe\n");
}
	
	printf("Isso corresponde a %f Milhas", milha);
	
	
}
