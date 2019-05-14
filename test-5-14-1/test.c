#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 15;
//	int count = 0;
//	while (i)
//	{
//		if (i % 2 == 1)
//		{
//			count++;
//			i = i / 2;
//		}
//	}
//	printf("%d\n", count);
//	system("pause");
//	return 0; 
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个数\n");
//	scanf("%d", &n);
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//			count++;
//	}
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个数\n");
//	scanf("%d", &n);
//	int count = 0;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int n= 0;
//	int i = 0;
//	printf("请输入一个数\n");
//	scanf("%d", &n);
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//void fun(int n)
//{
//	int i = 0;
//	if (n > 0)
//	{
//		i = n % 10;
//		n = n / 10;
//		fun(n);
//		printf("%d ", i);
//	}
//
//
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个数\n");
//	scanf("%d", &n);
//    fun(n);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
int fun2(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

int fun1(int x, int y)
{
	return fun2(x^y);
}

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	int ret = fun1(m, n);
	printf("%d", ret);
	system("pause");
	return 0;
}
 