#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int a = 1;
//	int* p = &a;
//	printf("%d\n", *p);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	int* px = &a;
//	char* py = &a;
//	printf("%d %d\n", *px, *py);
//	system("pause");
//	return 0;
//}
// int main()
 //{
 //char arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//    int i = 0;

//char* p = arr;
//int i = 0;
//for (i = 0; i < 10; i++)
		//{
		//	*(p + i) = 0;
	
		//	printf("%d ", arr[i]);
		//}
//	int* p = arr;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 0;
//
//		printf("%d ", arr[i]);
//	}
  // printf("\n");
	//system("pause");
//return 0;
//}
//int main()
//{
//	int i = 1;
//	int* px = &i;
//	char* py = &i;
//	printf("%d\n", px);
//	printf("%d\n", px + 1);
//	printf("%d\n", py);
//	printf("%d\n", py + 1);
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//	double i = 0;
//	double* p = &i;
//	printf("%p\n", p);
//		printf("%p\n", p + 1);
//		system("pause");
//		return 0;
//}
int main()
{
	int arr[10] = { 0 };
	//printf("%d\n", &arr[9] - &arr[0]);
	printf("%d\n", &arr[0] - &arr[9]);
	system("pause");
	return 0;
}

 