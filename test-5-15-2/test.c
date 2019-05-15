#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
	/*int a, b;
	printf("请输入两个数\n");
	scanf("%d %d", &a, &b);*/
//	int c = a + ((b - a) >> 1);
//	printf("c=%d\n", c);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a, b;
//	printf("请输入两个数\n");
//	scanf("%d %d", &a, &b);
//	int c = ((a&b) + ((a^b) >> 1));
//	printf("c=%d\n", c);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr[7] = { 1, 2, 3, 4, 3, 2, 1 };
//	int i = 0;
//	for (i = 1; i < 7; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];
//	}
//	printf("%d\n", arr[0]);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num = 0;
	int sum = 0;
	int m = 0;
	int i = 0;
	scanf("%d", &num);
	for (i = 31; i > 0; i--)
	{
		m= num & 1;
		sum = sum + (m << i);   
		num = num >> 1;

	}
	printf("%u", sum);
	system("pause");
	return 0;
}