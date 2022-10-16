#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include "stdio.h"
struct AddComplex {
	float real;
	float img;
};
struct AddComplex add(struct AddComplex x, struct AddComplex y);
int main()
{
	struct AddComplex x,y,sum;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	scanf("%f%f", &x.real,&x.img);
	
	printf("For 2nd complex number:\n");
	printf("Enter real and imaginary respectively: ");
	scanf("%f%f", &y.real, &y.img);

	sum = add(x, y);

	printf("Sum=%.1f+%.1fi\n",sum.real,sum.img);
}
struct AddComplex add(struct AddComplex x, struct AddComplex y)
{
	struct AddComplex sum;
	sum.real = x.real + y.real;
	sum.img = x.img + y.img;
	return sum;
}
