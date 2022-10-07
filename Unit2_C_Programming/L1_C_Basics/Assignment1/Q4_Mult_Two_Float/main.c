/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */


#include "stdio.h"

int main()
{
	float num1 , num2, product;
	printf("Enter two numbers: ");
	fflush (stdin); fflush (stdout);
	scanf("%f %f",&num1,&num2);
	fflush (stdin); fflush (stdout);
	product=num1*num2;
	printf("Product: %f",product);
	return 0;
}
