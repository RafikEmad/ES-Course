/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	int n;
	fflush(stdin);fflush(stdout);
	printf("Maximum no. of inputs \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	int x=0;
	float num,sum=0;
	for (int i=0;i<n;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("Enter n%d: ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&num);
		if (num>=0)
		{
			sum=sum+num;
			x++;
		}
		else
			break;
	}

	printf("Average=%.2f",sum/x);
}
