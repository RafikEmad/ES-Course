#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"stdio.h"

int main()
{
	int a[20];
	int g;
	printf("Enter nb of elements: ");
	scanf("%d", &g);
	int* p = &a;
	for (int x = 0; x < g; x++)
	{
		printf("element - %d: ", x + 1);
		scanf("%d", (p+x));
	}
	printf("Expected Output:\n\nThe elements of array in reverse order are :\n");
	
	
	for (int i = g-1; i >= 0; i--)
	{
		printf("element - %d : %d\n",i+1,*(p+i));
	}
}