/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */
#include "stdio.h"

int Last_Occurence(int a[],int size,int num);

int main()
{
	int a[10];
	int x;
	int num;

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

	fflush(stdin);fflush(stdout);
	printf("the number is ");

	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);fflush(stdout);

	printf("result = %d",Last_Occurence(a,x,num));
}

int Last_Occurence(int a[],int size,int num)
{
	int i,flag=0;

	for ( i=size-1;i>=0;i--)
	{
		if (a[i]==num)
			{
				flag=1;
				break;
			}
	}
	if (flag==1)
	{
		flag=0;
		return i;
	}

	else
		return -1;
}

