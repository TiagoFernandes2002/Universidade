

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    int original, invertido = 0;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned)time_t(&t));
    original = (rand() % 900) + 100;

    printf("Original = %d\n", original);

    while (original > 0)
    {
        invertido = invertido * 10 + (original % 10);
        original /= 10;
    }

    printf("Invertido = %ld\n", invertido);

    return 1;
}

