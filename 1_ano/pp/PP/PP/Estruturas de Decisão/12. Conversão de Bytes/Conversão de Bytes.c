#include <stdio.h>

main()
{
	double Bytes, KB,MB,GB,TB;
	
	printf ("Insira o numero de Bytes a converter (ex. 1858656563) :");
	scanf (" %lf", &Bytes);
	
	KB = Bytes/1024;
	MB = KB /1024;
	GB = MB/1024;
	TB = GB/1024;
	
	if (TB>=1)
	{
		printf ("\n %.1lf Bytes sao : %.3lf TB",Bytes,TB);
	}
	else if (GB>=1)
	{
		printf ("\n %.1lf Bytes sao : %.3lf GB",Bytes,GB);
	}
	else if (MB>=1)
	{
		printf ("\n %.1f Bytes sao : %.3f MB",Bytes,MB);
	}
	else if (KB>=1 || Bytes<=1024 && Bytes>=0)
	{
		printf ("\n %.1lf Bytes sao : %.3lf KB",Bytes,KB);
	}
	else
	{
		printf ("\n Erro! Insira um valor valido! \n");
	}
}
