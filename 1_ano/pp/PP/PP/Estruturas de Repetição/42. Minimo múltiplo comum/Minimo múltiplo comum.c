#include <stdio.h>

int mmc (int x, int y)
{
	int i,s,Total;
	for (i=2;i<=(x*y);i++)
	{
		for (s=2;s<(x*y);s++)
		{
			if (y*s==x*i)
			{
				Total = x*i;
				return Total;
				break;
			}
		}
	}
}
main()
{
	int Temp,x,y;
	
	printf ("Insira 2 numeros inteiros : ");
	scanf (" %d %d", &x,&y);
	Temp = mmc(x,y);
	printf ("mmc : %d",Temp);
}
