/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: rafik
 */


#include "stdio.h"

int main()
{
	int a[100];
	int num, new_element;
	fflush(stdin);fflush(stdout);
	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	for (int i=0;i<num;i++)
	{
		a[i]=(i+1)*11;
		fflush(stdin);fflush(stdout);
		printf("%d ",a[i]);
	}

	fflush(stdin);fflush(stdout);
	printf("\nEnter the elements to be searched: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&new_element);

	for (int i=0;i<num;i++)
	{
		if (a[i]==new_element)
		{
			printf("Number found at the location = %d",i+1);
		}
	}

}
