/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include "stdio.h"

int factorial(int a);

int main()
{
	int a;

	fflush(stdin);	fflush(stdout);
	printf("Enter a positive integer: ");

	fflush(stdin);	fflush(stdout);
	scanf("%d",&a);

	printf("Factorial of %d = %d",a,factorial(a));

	return 0;
}

int factorial(int a)
{
	if(a==1)
		return 1;
	else
	{
		return a*factorial(a-1);
	}

}
