#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr=%p\n", arr);
//	printf("&arr=%p\n", &arr);
//	printf("arr+1=%p\n", arr + 1);
//	printf("&arr+1=%p\n", &arr + 1);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void print_arr1(int arr[3][5], int row, int col)
//{
//	int i = 0;
//	for (i = 0;i < row; i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print_arr2(int(*arr)[5], int row, int col)
//{
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	print_arr1(arr, 3, 5);
//数组名arr表示首元素的地址
//但是二维数组的首元素时二维数组的第一行
//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
//可以用数组指针来接收
//	print_arr2(arr, 3, 5);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//void swap(int* arr1, int* arr2, int length)
//{
//	for (int i = 0;i < length;i++) {
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//	for (int i = 0;i < 5;i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0;i < 5;i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 6,7,8,9,10 };
//	swap(arr1,arr2,5);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 6,7,8,9,10 };
//	int i = 0;
//	int j = 0;
//	int k=0;
//	for (k = 0;k < 5;k++)
//	{
//		arr1[k] = arr1[k] ^ arr2[k];
//		arr2[k] = arr1[k] ^ arr2[k];
//		arr1[k] = arr1[k] ^ arr2[k];
//	}
//	for (i = 0;i < 5;i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (j = 0;j < 5;j++)
//	{
//		printf("%d ", arr2[j]);
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 6,7,8,9,10 };
//	for (int i = 0;i < 5;i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//	for (int i = 0;i < 5;i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int j = 0;j < 5;j++)
//	{
//		printf("%d ", arr2[j]);
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 6,7,8,9,10 };
//	int arr3[5];
//	for (int i = 0;i < 5;i++)
//	{
//		arr3[i] = arr1[i];
//	}
//	for (int j = 0;j < 5;j++)
//	{
//		arr1[j] = arr2[j];
//	}
//	for (int k = 0;k < 5;k++)
//	{
//		arr2[k] = arr3[k];
//	}
//		for (int i = 0;i < 5;i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int j = 0;j < 5;j++)
//	{
//		printf("%d ", arr2[j]);
//	}
//	system("pause");
//	return 0;	
//}

