/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include "stdio.h"

void Prime_numbers(int a,int b);

int main()
{
	int a, b;
	fflush(stdin);	fflush(stdout);
	printf("Enter two numbers (intervals): ");

	fflush(stdin);	fflush(stdout);
	scanf("%d%d",&a,&b);

	Prime_numbers(a,b);

	return 0;
}

void Prime_numbers(int a,int b)
{
	int z[100];
	int i;
	int j;

	printf("Prime numbers between %d and %d are: ",a,b);

	for (int m=a,x=0;m<=b;m++,x++)
	{
		z[x]=m;
	}

	for (i=0;i<(b-a)+1;i++)
	{
		for (j=2;j<=z[i];j++)
		{
			if(z[i]%j==0)
			{
				break;
			}
		}
		if(z[i]==j)
		{
			printf("%d ",z[i]);
		}

	}



}
