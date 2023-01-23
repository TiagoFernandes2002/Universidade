#include <stdio.h>
#define LINE 13
#define COLUMN 13

//---Eventualmente para futuro---
/*typedef struct player_struct{
 int x;
 int y;
}player;*/



int matrix_print(int matrix[][COLUMN],int i,int j,int player_pos1)
{
	player_pos1= matrix[7][7];
	//player p1={7,7},p2={3,6},p3={8,9};
	for(i=0;i<LINE;i++)
	{
	
		for(j=0;j<COLUMN;j++)
		if(matrix[i][j]=player_pos1) printf(" A ");
		else if(matrix[i][j]!=0) printf(" %d ",matrix[i][j]);
		else printf("   ");
		
		printf("\n");
	}
	
	printf("\n\n\n");
}


int matrix_initialize(int matrix[][COLUMN],int i,int j)
{
	for(i=0;i<LINE;i++)
		for(j=0;j<COLUMN;j++)
			matrix[i][j]=0;
}

int matrix_fill(int matrix[][COLUMN],int i,int j)
{
	int aux=0;
	int index=0;
	
	for(j=0;j<COLUMN;j++)
	{
		aux=j+1;
		if(j>0 && j<7)
		{
			matrix[6][j]=aux;
			for(index=0;index<=j;index++) matrix[6-index][j]=aux;
			for(index=0;index<=j;index++) matrix[6+index][j]=aux;
		}
		
		if(j>=7 && j<12)
		{
			matrix[6][j]=aux;
			for(index=0;index<(13-j);index++) matrix[6-index][j]=aux;
			for(index=0;index<(13-j);index++) matrix[6+index][j]=aux;
		}

	}
}

int main()
{
	int player_pos1;
	int i=0,j=0;
	int matrix[LINE][COLUMN]; 
	//player p1={7,7},p2={3,6},p3={8,9};
	
	
	matrix_initialize(matrix,i,j);
	//matrix_print(matrix,i,j);

	matrix_fill(matrix,i,j);
	matrix_print(matrix,i,j);
}
 
