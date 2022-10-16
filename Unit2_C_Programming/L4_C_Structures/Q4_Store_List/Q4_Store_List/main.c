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
	struct Student x[3];
	printf("Enter information of students:\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf("For roll number: ");
		scanf("%d", &x[i].roll_num);
		printf("Enter name: ");
		scanf("%s", x[i].name);
		printf("Enter marks: ");
		scanf("%f", &x[i].marks);
	}
	printf("\nDisplaying Information\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Information for roll number %d: \n",x[i].roll_num);
		printf("name: %s\n", x[i].name);
		printf("Marks: %.0f\n", x[i].marks);
	}
}