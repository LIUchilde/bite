#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 2;
	int b = 1;
	int c = 3;
	int t = 0;
	if (a < b)
	{
		t = a, a = b, b = t;
	}
	if (a < c)
	{
		t = a, a = c, c = t;
	}
	if (b < c)
	{
		t = b, b = c, c = t;
	}
	printf("%d %d %d", a, b, c);
	system("pause");
	return 0;
}
 