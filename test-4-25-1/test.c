#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void ret(int n)
{
	if (n % 10 != 0)
	{
		printf("%d", n % 10);
		ret(n / 10);


	}
}

int main()
{
	int n = 0;
	printf("请打印一个整数\n");
	scanf("%d", &n);
	ret(n);
	system("pause");
	return 0;
}
 