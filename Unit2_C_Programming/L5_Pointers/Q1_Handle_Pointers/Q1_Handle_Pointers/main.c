#include"stdio.h"

int main()
{
	int m = 29;
	printf("Address of m : %p\nValue of m : %d\n", &m, m);
	int* ab = &m;
	printf("Now ab is assigned with address of m\n");
	printf("Address of pointer ab : %p\nContent of pointer ab : %d\n", &m, m);
	m = 34;
	printf("The value of m assigned to %d now.\n", m);
	printf("Address of pointer ab : %p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);
	printf("The pointer variable ab is assigned with the value %d now\n", m);
	*ab = 7;
	printf("Address of m : %p\n", ab);
	printf("Value of m : %d\n", *ab);
}