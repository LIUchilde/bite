#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#define true 1
//#define fauls 0
//typedef int bool;
//bool yangsearch(int arr[4][4], int k, int* i, int* j)
//{
//	if (k<arr[0][0] || k>arr[3][3])
//	{
//		return fauls;
//	}
//	int row=0;
//	int col=3;
//	while (row >= 0 && col < 4)
//	{
//		if (k == arr[row][col])
//		{
//			*i = row;
//			*j = col;
//			return true;
//		}
//		else if (k>arr[row][col])
//		{
//			row++;
//		}
//		else if (k < arr[row][col])
//		{
//			col--;
//		}
//	}
//	return fauls;
//
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int arr[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
//	printf("请输入要查找的数\n");
//	scanf("%d", &k);
//	bool b = yangsearch(arr, k, &i, &j);
//	if (b)
//	{
//		printf("检查到：%d,位置为：%d ,%d\n", k, i, j);
//	}
//
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

int main()
{

	int i = 0;
	int j = 9;
	int arr[10] = { 0,1, 9, 2, 8, 3,4, 7, 6, 5 };
	for (i = 0; i <=j; i++)
	{
		if (arr[i] % 2 != 0)
		{
			continue;
		}
		else
		{
		    int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			if (arr[j] % 2 == 0)
			{
				j--;
				i--;
			}
		}
		
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
 