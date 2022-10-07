/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */


#include "stdio.h"

int main()
{
	int x,factorial=1;
	printf("Enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if (x==0)
		printf("Factorial = 1");
	else if (x>0)
	{
		while (x!=0)
		{
			factorial=factorial*x;
			x=x-1;

		}
		printf("Factorial = %d",factorial);
	}
	else
		printf("Error!!! Factorial of negative number doesn't exist");
	return 0;
}
