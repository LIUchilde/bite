#define  _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[10][10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				arr[i][j] = 1;
//			}
//			else if (i>1 && j > 0)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%3d", arr[i][j]);
//			
//		}
//		printf("\n");
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
//	int k = 0;
//	int arr[10][10] = { 0 };
//	for (i = 0; i < 10; i++)
//			{
//				for (j = 0; j <= i; j++)
//				{
//					if (j == 0 || i == j)
//					{
//						arr[i][j] = 1;
//					}
//					else if (i>1 && j > 0)
//					{
//						arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//					}
//				}
//			}
//	for (i = 0; i < 10; i++)
//	{
//		for (k = 0; k < 10 - i; k++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%6d", arr[i][j]);
//
//		}
//		printf("\n");
//	}
//			
//			printf("\n");
//			system("pause");
//			return 0;	
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			printf("killerÊÇ:%c", killer);
//		}
//	}
//	system("pause");
//	return 0;
//}
 