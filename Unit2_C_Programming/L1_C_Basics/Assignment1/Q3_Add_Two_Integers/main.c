/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */
#include "stdio.h"

int main()
{
	int num1 , num2, sum;
	printf("Enter two integer: ");
	fflush (stdin); fflush (stdout);
	scanf("%d %d",&num1,&num2);
	fflush (stdin); fflush (stdout);
	sum=num1+num2;
	printf("Sum: %d",sum);
	return 0;
}

