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
	int num, new_element,location;
	fflush(stdin);fflush(stdout);
	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	for (int i=0;i<num;i++)
	{
		a[i]=i+1;
		fflush(stdin);fflush(stdout);
		printf("%d ",a[i]);
	}

	fflush(stdin);fflush(stdout);
	printf("\nEnter the element to be inserted: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&new_element);

	fflush(stdin);fflush(stdout);
	printf("Enter the location: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&location);

	for (int i=num;i>=location;i--)
	{
		a[i]=a[i-1];
	}

	a[location-1]=new_element;

	for (int i=0;i<num+1;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("%d ",a[i]);
	}
}
