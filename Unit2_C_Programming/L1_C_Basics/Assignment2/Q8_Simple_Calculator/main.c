/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */
#include "stdio.h"

int main()
{
	char x;
	float a,b;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&x);
	fflush(stdin);fflush(stdout);
	printf("Enter two operands: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&a,&b);
	fflush(stdin);fflush(stdout);
	switch(x)
	{
	case'+':
		printf("%0.1f + %0.1f = %0.1f",a,b,a+b);
		break;
	case'-':
		printf("%0.1f - %0.1f = %0.1f",a,b,a-b);
		break;
	case'*':
		printf("%0.1f * %0.1f = %0.1f",a,b,a*b);
		break;
	case'/':
		printf("%0.1f / %0.1f = %0.1f",a,b,a/b);
		break;
	default:
		printf("Error! operator is not correct");
		break;
	}
	return 0;
}


