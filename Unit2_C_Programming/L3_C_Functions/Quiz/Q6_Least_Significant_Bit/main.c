/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include "stdio.h"

#include "stdbool.h"

bool Least (int num);

int main ()
{
	int num;

	fflush(stdin);fflush(stdout);
	printf("Input Number = ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	fflush(stdin);fflush(stdout);
	printf("result = %d",Least(num));

}
bool Least (int num)
{
		return num&(1<<3);
}

