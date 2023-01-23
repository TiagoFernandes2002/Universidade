/*
Escreva um programa que pe�a um n�mero ao utilizador e imprima 
uma forma de diamante, coma a largura e altura desse n�mero, 
constitu�da por carateres '-' e '*'.

O n�mero dever� ser inteiro e impar.
Para impress�o no ecr� deve utilizar o c�digo printf("*") e printf("-").
Deve utilizar estruturas de repeti��o.
Por exemplo, para o n�mero 7, a forma impressa seria:

---*---
--***--
-*****-
*******
-*****-
--***--
---*---

*/


#include <stdio.h>

int main()
{
  int n = 7, inc = 2, astx = 1, l, c;

  for (l = 1; l <= n; l++) {	
    for (c = 1; c <= n; c++) {
		if ( c > (n-astx)/2 && c <= ((n-astx)/2+astx)) printf("*"); 
		else printf("-");
	}
    printf("\t | l = %i | astx = %i | inc = %i\n", l,astx,inc);
	if (l>n/2) inc=-2;
	astx= astx + inc;
   
  }
}
