/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	int num;
	printf("Enter a integer: ");
	fflush (stdin); fflush (stdout);
	scanf("%d",&num);
	fflush (stdin); fflush (stdout);
	printf("You entered: %d",num);
	return 0;
}
