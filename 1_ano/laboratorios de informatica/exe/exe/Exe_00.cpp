

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    printf("Usando acentuação em Portugu%cs\n",136);

    setlocale(LC_ALL, "Portuguese");

    printf("Usando acentuação em Português\n");

    return 1;
}
