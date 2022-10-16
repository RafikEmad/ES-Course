#include"stdio.h"

int main()
{
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	char* p = a;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%c ", *(p + i));
	}
}