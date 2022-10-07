/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */

#include "stdio.h"

int Power(int b ,int p);

int main()
{
	int base;
	int power;

	fflush(stdin);	fflush(stdout);
	printf("Enter base number: ");

	fflush(stdin);	fflush(stdout);
	scanf("%d",&base);

	fflush(stdin);	fflush(stdout);
	printf("Enter power number (positive number): ");

	fflush(stdin);	fflush(stdout);
	scanf("%d",&power);

	fflush(stdin);	fflush(stdout);
	printf("%d",Power(base,power));

	return 0;
}

int Power(int b , int p)
{

	if (p!=0)
	{
		return b*Power(b,p-1);
	}
	else
		return 1;
}

