/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: rafik
 */


#include "stdio.h"
#include "stdlib.h"

int main()
{
	float sum=0;
	int n;
	float *ptr;
	fflush(stdin);fflush(stdout);
	printf("Enter numbers of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	//float a[n];
	ptr =(float*)malloc(n* sizeof(float));
	fflush(stdin);fflush(stdout);

	for (int i=0;i<n;i++)
	{
		fflush(stdin);fflush(stdout);
		printf("Enter number: ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&ptr[i]);
		sum=sum+ptr[i];
	}
	printf("Average = %0.2f",sum/n);


}
