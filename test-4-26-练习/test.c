#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//    int len= strlen("abc");
//	printf("%d\n", len);
//	system("pause");
//	return 0;
//}

//int my_strlen(char* str)
//{
//	
//	
//		if (*str == '\0')
//		{
//			return 0;
//		}
//		else
//		{
//			str++;
//			return 1 + my_strlen(str );
//		}
//	
//
//}
//int main()
//{
//	int len = my_strlen("abc");
//		printf("%d\n", len);
//		system("pause");
//		return 0;
//}

//int main()
//{
//	char arr[] = "abc";
//	printf("%d\n", &arr[2] -& arr[0]+1);
//	system("pause");
//	return 0;
//
//		
//}
//int my_strlen(char* arr)
//{
//	char* str = arr;
//
//	while (*arr)
//	{
//		arr++;
//	}
//	return arr - str;
//
//}
//int main()
//{
//	char arr[] = "abc";
//	int ret= my_strlen(arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char b ='0';
//	printf("%d\n", b);
//	printf("%d\n", '1');
//	printf("%c\n", 98);
//
//
//
//	system("pause");
//	return 0;
//
//
//
//}
//int main()
//{
//	int arr[10] = { 0 };       
//	printf("%p\n", arr);       //数组首元素的地址
//	printf("%p\n", &arr[0]);    //数组首元素的地址
//	printf("%p\n", &arr);        //数组的地址
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 2, 3, 4, 5, 6 };
	int arr3[5] = { 3, 4, 5, 6, 7 };
	int* arr[3] = { arr1, arr2, arr3 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
		//	printf("%d ", arr[i][j]);
			printf("%d ", *(arr[i] + j));//arr[j]=*(arr+j)

		}
		printf("\n");
	}
	system("pause");
	return 0;

}