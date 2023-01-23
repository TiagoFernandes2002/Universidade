#include <stdio.h>

main()
{
	int i;
	float B,H,Area;
	
	for (i=1;i<=50;i++)
	{
		printf ("Insira a base do %d triangulo : ", i);
		scanf (" %f",&B);
		printf ("Insira a altura do %d triangulo : ", i);
		scanf (" %f",&H);
		printf ("\n");
		Area = B*H/2;
		printf ("Area do %d Triangulo : %.2f (u.m) \n \n",i,Area);
	}
}
