/*
 * main.c
 *
 *  Created on: Oct 3, 2022
 *      Author: rafik
 */

#include "stdio.h"

int main()
{
	char c;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	if (c=='a'||c=='A'|| c=='e'|| c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
	{
		printf("%c is a vowel.",c);
		fflush(stdin);fflush(stdout);
	}
	else
	{
		printf("%c is a consonant.",c);
		fflush(stdin);fflush(stdout);
	}
	return 0;
}
