#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include "stdio.h"
struct AddDistances {
	int feet;
	float inch;
};
int main()
{
	struct AddDistances x,y,sum;
	printf("Enter information of 1st distance:\n");
	printf("Enter feet: ");
	scanf("%d", &x.feet);
	printf("Enter inch: ");
	scanf("%f", &x.inch);
	
	printf("Enter information of 2nd distance:\n");
	printf("Enter feet: ");
	scanf("%d", &y.feet);
	printf("Enter inch: ");
	scanf("%f", &y.inch);

	sum.feet = x.feet + y.feet;
	sum.inch = x.inch + y.feet;
	
	if (sum.inch > 12)
	{
		sum.inch = sum.inch - 12;
		sum.feet++;
	}

	printf("Sum of distances= %d\' - %.1f",sum.feet,sum.inch);
}