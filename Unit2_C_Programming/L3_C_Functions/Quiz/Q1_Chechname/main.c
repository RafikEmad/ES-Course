/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */
#include "stdio.h"
#include "string.h"
int main()
{
	char a[100];
	char b[100];

	fflush(stdin);fflush(stdout);
	printf("Enter string: ");
	fflush(stdin);fflush(stdout);
	gets(a);

	fflush(stdin);fflush(stdout);
	printf("Enter username: ");

	fflush(stdin);fflush(stdout);
	gets(b);

	int x;

	x=stricmp(a,b);
	if (x==0)
		printf("same");
	else
		printf("not same");

	return 0;
}

