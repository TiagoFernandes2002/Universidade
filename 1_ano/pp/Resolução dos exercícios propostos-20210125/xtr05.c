/*
Escreva um programa que peça um número ao utilizador e imprima 
uma forma de diamante, coma a largura e altura desse número, 
constituída por carateres '-' e '*'.

O número deverá ser inteiro e impar.
Para impressão no ecrã deve utilizar o código printf("*") e printf("-").
Deve utilizar estruturas de repetição.
Por exemplo, para o número 7, a forma impressa seria:

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
