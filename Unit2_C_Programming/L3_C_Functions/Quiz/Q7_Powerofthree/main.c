/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include "stdio.h"
#include "stdbool.h"

bool Powerofthree(int num);

int main()
{
	int num;
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);fflush(stdout);
	printf("==> %d",Powerofthree(num));

}

bool Powerofthree(int num)
{
	if (num%3==0)
	{
		return Powerofthree(num/3);
	}
	if (num==1)
	{
		return 0;
	}
	else
		return 1;
}
