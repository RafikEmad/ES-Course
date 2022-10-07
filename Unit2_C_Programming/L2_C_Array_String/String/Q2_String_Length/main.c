/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: rafik
 */


#include "stdio.h"
#include "string.h"

int main()
{
	char a[100];
	char b[100];

	fflush(stdin);fflush(stdout);
	printf("Enter the string: ");

	fflush(stdin);fflush(stdout);
	gets(a);

	for (int i=0;i<strlen(a);i++)
	{
		b[i]=a[strlen(a)-i-1];
	}

	b[strlen(a)]=0;

	fflush(stdin);fflush(stdout);
	printf("Reverse string is: %s",b);


	return 0;
}
