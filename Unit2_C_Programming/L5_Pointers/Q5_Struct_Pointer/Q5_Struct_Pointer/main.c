#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"stdio.h"

struct person
{
	char name[20];
	int id;
};

int main()
{
	struct person x;
	struct person* y = &x;
	scanf("%s", y->name);
	scanf("%d", &y->id);
	printf("Employee Name: %s\n", y->name);
	printf("Employee ID: %d", y->id);
}