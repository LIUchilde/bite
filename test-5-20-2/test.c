#define  _CRT_SECURE_NO_WARNINGS 1
//冒泡排序法
//#include<stdio.h>
//#include<stdlib.h>
//void sort(int arr[], int n)
//{
//	int i = 0;
//	int j = 0;
//	int temp;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 9 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0, 1, 9, 2, 8, 3, 7, 4, 6, 5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n"); 
//	system("pause");
//	return 0;
//}

//升级版冒泡排序
#include<stdio.h>
#include<stdlib.h>
void sort(int arr[], int n)
{
	int left = 0;
	int right = n - 1;
	int temp;
	while (left < right)
	{
		//从左向右遍历出最大的数放到数组的最右端
		for (int i = left; i < right; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		right--;
		for (int j = right; j > left; j--)
		{
			//从右向左遍历出最小的数放到数组的最左端
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		left++;
	}
}
int main()
{
	int arr[10] = { 0, 1, 9, 2, 8, 3, 7, 4, 6, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, sz);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
 