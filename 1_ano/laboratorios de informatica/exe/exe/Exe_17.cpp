

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
    int num, original, inverso = 0;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite um n�mero:");
    scanf("%d", &num);

    original = num;
    //for ( ; nUm > 0; )
    while (num > 0)
    {
        inverso = inverso * 10 + (num % 10);
        num /= 10;
    }

    if (original == inverso)
        printf("Capicua\n", original);
    else
        printf("N�o � capicua\n", inverso);

    return 1;
}

