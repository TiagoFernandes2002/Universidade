

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    printf("Usando acentua��o em Portugu%cs\n",136);

    setlocale(LC_ALL, "Portuguese");

    printf("Usando acentua��o em Portugu�s\n");

    return 1;
}
