/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: rafik
 */

#include "stdio.h"
#include "stdlib.h"

int main()
{
	int row, col;

	fflush(stdin);fflush(stdout);
	printf("Enter rows and columns of matrix: ");

	fflush(stdin);fflush(stdout);
	scanf("%d %d",&row,&col);

	int* ptr = malloc((row * col) * sizeof(int));

	fflush(stdin);fflush(stdout);
	printf("Enter elements of matrix:\n");

	int g=0;

	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			fflush(stdin);fflush(stdout);
			printf("Enter elements a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&ptr[g]);
			g++;
		}
	}

	g=0;

	printf("Entered Matrix:\n");
// [0] [1] [2]
// [3] [4] [5]
	for (int g=0,i=0;i<row;g+=3,i++)
	{
		fflush(stdin);fflush(stdout);
		printf("%d\t%d\t%d \n",ptr[g],ptr[g+1],ptr[g+2]);
		fflush(stdin);fflush(stdout);
		//g=g+3;
	}
	g=0;
	// [0] [1] [2]
	// [3] [4] [5]
	// [0] [3]
	// [1] [4]
	// [2] [5]
	printf("Transpose of Matrix:\n");
	for (int i=0;i<col;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("%d\t%d \n",ptr[g],ptr[g+col]);
		fflush(stdin);fflush(stdout);
		g++;
	}


	return 0;
}

