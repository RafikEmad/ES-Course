/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	int a[10];
	int b[10];
	int x;
	int y;

	fflush(stdin);fflush(stdout);
	printf("Enter 1st array size: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	fflush(stdin);fflush(stdout);
	printf("Enter 1st array elements: ");

	for (int i=0;i<x;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%d",&a[i]);
	}

	fflush(stdin);fflush(stdout);
	printf("Enter 2nd array size: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);

	fflush(stdin);fflush(stdout);
	printf("Enter 2nd array elements: ");

	for (int i=0;i<y;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%d",&b[i]);
	}

	for (int i=0;i<10;i++)
	{
		a[i]=a[i]+b[i];
		b[i]=a[i]-b[i];
		a[i]=a[i]-b[i];
	}
	for (int i=0;i<y;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("%d ",a[i]);
	}
	printf("\n");
	for (int i=0;i<x;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("%d ",b[i]);
	}
	return 0;
}

