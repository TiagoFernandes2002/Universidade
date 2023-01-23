#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int	alt, larg;
    int per, area;

    setlocale(LC_ALL, "Portuguese");
    printf("introduza a altura do retângulo: ");
    scanf_s("%d",&alt);
    printf("introduza a largura do retângulo: ");
    scanf_s("%d", &larg);
    area = alt * larg;
    per = 2 * (alt + larg);
    printf("Perímetro = %d\n",per);
    printf("Área = %d\n", area);

    return 1;
}

