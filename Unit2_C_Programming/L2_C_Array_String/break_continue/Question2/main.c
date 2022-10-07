/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	int num, product=1;
	for (int i=0;i<4;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("Enter num%d: ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&num);
		if (num==0)
			continue;
		product=product*num;

	}

	printf("product=%d",product);
}

