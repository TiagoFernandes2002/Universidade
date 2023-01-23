#include <stdio.h>

int mdc (int x,int y)
{
	int i;
	if (x>y)
	{
		for (i=x;i>=1;i--)
		{
			if (x%i==0 && y%i==0)
			{
			return i;
			break;
			}
		}
	}
}
	
main()
{
	int x,y,Temp;
	
	printf ("Insira 2 numeros inteiros : ");
	scanf (" %d %d", &x, &y);
	Temp = mdc(x,y);
	printf ("Maximo Divisor comum : %d",Temp);
}
