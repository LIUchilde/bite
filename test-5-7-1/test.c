#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int j = 0;
//	int t = 0;
//	printf("请输入十个数\n");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		int min = i;
//		for (j = i + 1; j < 10; j++)
//		{
//			if (arr[min]>arr[j])
//			{
//				min = j;
//				t = arr[min];
//				arr[min] = arr[i];
//				arr[i] = t;
//			}
//			
//		}
//
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	int arr[3][3];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		sum += arr[i][i];
//	}
//	printf("对角线之和为：%d", sum);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int t1= 0;
//	int t2 = 0;
//	int arr[11] = { 2, 3, 4, 5,7, 8, 9, 13,14,15 };
//	int k = 0;
//	int end = arr[9];
//	printf("原始数组为:\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n插入的数字为：\n");
//	scanf("%d", &k);
//	if (k>end)
//	{
//		end = k;
//	}
//	else
//	{
//		for (i = 0; i < 10; i++)
//		{
//			if (arr[i]>k)
//			{
//				t1 = arr[i];
//				arr[i] = k;
//				for (j = i + 1; j < 11; j++)
//				{
//					t2 = arr[j];
//					arr[j] = t1;
//					t1 = t2;
//				}
//				break;
//			}
//			
//		}
//		
//	}
//	printf("插入元素后的数组为:\n");
//	for (i = 0; i < 11; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//		return 0;
//}


 