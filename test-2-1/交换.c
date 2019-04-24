#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
	printf("请输入两个数\n");
	scanf("%d %d", &a, &b);
	t=a , a =b , b = t;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}
 