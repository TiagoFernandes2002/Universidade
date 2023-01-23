

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char aux, str[20] = "LABINF";
    int i,size;

    size = strlen(str);
    for (i = 0; i < size/2; i++)
    {
        aux = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = aux;
    }
    printf("%s\n", str);

    return 1;
}
