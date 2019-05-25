#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//void fun(int arr[])
//{
//	int i = 0;
//	int temp;
//	for (i = 0; i <=5; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[9 - i];
//		arr[9 - i] = temp;
//	}
//}
//int main()
//{
//	int arr[10] = { 0, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
//	fun(arr);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
 
//#include<stdio.h>
//#include<stdlib.h>
//void fun(int arr1[])
//{
//	int arr2[10];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr2[i] = arr1[9 - i];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		arr1[i] = arr2[i];
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 0, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
//	fun(arr1);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int fun(int arr[])
//{
//	int second = arr[0];
//	int max = arr[1];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i]>max)
//		{
//			second = max;
//			max = arr[i];
//		}
//		if (arr[i]<max&&arr[i]>second)
//		{
//			second = arr[i];
//		}
//	}
//	return second;
//}
//
//int main()
//{
//	int arr[10] = { 0, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
//	int ret=fun(arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
void Buubble_sort(int arr[])
{
	int i = 0;
	int j = 0;
	int temp;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[10] = { 0, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	Buubble_sort(arr);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}