#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year; 
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		printf("%d是闰年", year);
	}
	else
	{
		printf("%d不是闰年", year);
	}
	system("pause");
	return 0;
}
 