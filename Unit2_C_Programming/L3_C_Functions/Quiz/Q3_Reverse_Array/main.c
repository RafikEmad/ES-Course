/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include "stdio.h"

void Reverse_Array(int a[],int size);

int main()
{
	int a[10];
	int x;

	fflush(stdin);fflush(stdout);
	printf("Enter array size: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	fflush(stdin);fflush(stdout);
	printf("Enter array elements: ");

	for (int i=0;i<x;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%d",&a[i]);
	}
	Reverse_Array(a,x);
}

void Reverse_Array(int a[],int size)
{
	for (int i=size-1;i>=0;i--)
	{
		if (i!=0)
			printf("%d,",a[i]);
		else
			printf("%d",a[i]);
	}
}
