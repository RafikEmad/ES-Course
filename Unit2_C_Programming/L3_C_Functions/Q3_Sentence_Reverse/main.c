/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: rafik
 */


#include "stdio.h"

void Sentence_Reverse();

int main()
{
	fflush(stdin);	fflush(stdout);
	printf("Enter a sentence: ");

	fflush(stdin);	fflush(stdout);

	Sentence_Reverse();

	return 0;
}

void Sentence_Reverse()
{
	char c;

	scanf("%c",&c);

	if (c!='\n')
	{
		Sentence_Reverse();
		printf("%c",c);
	}
}
