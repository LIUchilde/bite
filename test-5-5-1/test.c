#define  _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个五位数\n");
//	scanf("%d", &n);
//	if (n / 10000 == n % 10 && n % 10000 / 1000 == n % 100 / 10)
//	{
//		printf("这个数是回文数");
//	}
//	else
//	{
//		printf("这个数不是回文数");
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char i, j;
//	printf("请输入第一个字母\n");
//	scanf("%c", &i);
//	getchar();
//	switch (i)
//	{
//	case'm':
//		printf("monday\n");
//		break;
//	case'w':
//		printf("wendnesday\n");
//		break;
//	case'f':
//		printf("friday\n");
//		break;
//	case's':
//		printf("请输入下一个字母\n");
//		scanf("%c", &j);
//		if (j == 'a')
//		{
//			printf("saturday\n");
//			break;
//		}
//		if (j == 'u')
//		{
//			printf("sunday\n");
//			break;
//		}
//	case't':
//		printf("请输入下一个字母\n");
//		scanf("%c", &j);
//		if (j == 'u')
//		{
//			printf("tuesday\n");
//			break;
//		}
//		if (j == 'h')
//		{
//			printf("thursday\n");
//			break;
//		}
//	default:
//		printf("error\n");
//		break;
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	
//	char s[40] = "0";
//	char c = 0;
//	printf("请输入一组字符\n");
//	scanf("%s", s);
//	printf("请输入要删除的字符\n");
//	scanf("%c", &c);
//	int i = 0;
//	for (i = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] != c)
//		{
//			s[i++];
//		}
//	}
//	printf("%s", s);
//	system("pause");
//	return 0;
//}

//函数的调用

//#include<stdio.h>
//#include<stdlib.h>
//
//void fun(int* a, int* b)
//{
//	int t = 0;
//	t = *a;
//	*a = *b;
//	*b = t;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	fun(&a, &b);
//	printf("%d %d", a, b);
//	system("pause");
//	return 0;
//}


 