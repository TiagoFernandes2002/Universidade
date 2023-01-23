

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int	alt = 7, larg = 5;
    int per, area;

    setlocale(LC_ALL, "Portuguese");
    area = alt * larg;
    per = 2 * (alt + larg);
    printf("Perícmetro = %d\n", per);
    printf("Área = %d\n", area);
    //printf("Per%cmetro = %d\n", 237,per);
    //printf("%crea = %d\n", 193,area);

    return 1;
}
