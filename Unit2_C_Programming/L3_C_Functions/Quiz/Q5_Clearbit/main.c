/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include"stdio.h"

int Clearbit(int num,int x);
int main ()
{
	int x;
	int num;

	fflush(stdin);fflush(stdout);
	printf("Input Number = ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	fflush(stdin);fflush(stdout);
	printf("Bit position = ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	fflush(stdin);fflush(stdout);
	printf("result = %d",Clearbit(num,x));

}
int Clearbit(int num,int x)
{
	num &= ~(1<<x);
	return num;
}
