/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if (x%2==0)
	{
		printf("%d is even.",x);
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("%d is odd.",x);
		fflush(stdin);fflush(stdout);
	}
	return 0;
}
