#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include "stdio.h"
#define PI	3.1415
#define AREA(R) R*R*3.14
int main()
{
	int r;
	float area;
	printf("Enter the radius: ");
	scanf("%d",&r);
	area = AREA(r);
	printf("Area=%.2f",area);
}