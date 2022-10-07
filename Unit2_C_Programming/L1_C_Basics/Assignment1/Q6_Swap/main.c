/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	float a,b,temp;
	printf("Enter value of a: ");
	fflush (stdin); fflush (stdout);
	scanf("%f",&a);
	fflush (stdin); fflush (stdout);
	printf("Enter value of b: ");
	fflush (stdin); fflush (stdout);
	scanf("%f",&b);
	fflush (stdin); fflush (stdout);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %0.2f\n",a);
	fflush (stdin); fflush (stdout);
	printf("After swapping, value of a = %0.1f",b);
	return 0;
}


