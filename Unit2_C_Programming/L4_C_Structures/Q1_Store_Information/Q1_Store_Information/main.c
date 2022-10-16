#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include "stdio.h"
struct Student {
	char name[50];
	int roll_num;
	float marks;
};
int main()
{
	struct Student x;
	printf("Enter information of students:\n");
	printf("Enter name: ");
	scanf("%s", x.name);
	printf("Enter roll number: ");
	scanf("%d", &x.roll_num);
	printf("Enter marks: ");
	scanf("%f", &x.marks);

	printf("\nDisplaying Information\n");
	printf("name: %s\n", x.name);
	printf("Roll: %d\n", x.roll_num);
	printf("Marks: %.2f\n", x.marks);
}