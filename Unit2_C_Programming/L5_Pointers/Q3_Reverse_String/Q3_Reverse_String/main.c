#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"stdio.h"

int main()
{
	char a[100];
	printf("Input a string : ");
	//gets(a);
	scanf("%s", a);
	printf("Reverse of string is : ");

	int x = 0;
	while (a[x]!='\0')
	{
		x++;
	}
	char *p=&a;
	char b[100];
	char *prev = &b;
	for (int i = 0,z=x-1; i < x; i++,z--)
	{
		*(prev + z) = *(p + i);
	}
	*(prev + x) = '\0';
	printf("%s", prev);
}
