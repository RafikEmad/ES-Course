/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	float a,b,c;
	printf("Enter three numbers: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f %f",&a ,&b, &c);
	if (a>b)
	{
		if (a>c)
		{
			printf("largest number %0.2f",a);
			fflush(stdin);fflush(stdout);
		}
		else
			printf("largest number %0.2f",c);
	}
	else
	{
		if (b>c)
		{
			printf("largest number %0.2f",b);
			fflush(stdin);fflush(stdout);
		}
		else
			printf("largest number %0.2f",c);
	}
	return 0;
}

