

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define pi 3.14

int main()
{
    int	raio = 6;
    float per, area;

    setlocale(LC_ALL, "Portuguese");
    area = pi * pow(raio, 2);
    per = 2 * pi * raio;
    printf("Perímetro = %.2f\n", per);
    printf("Área = %.2f\n", area);

    return 1;
}

