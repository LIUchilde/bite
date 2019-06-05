#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void reserve(char* str, int left, int end)
//{
//	char temp = 0;
//	while (left < end)
//	{
//		temp = *(str + left);
//		*(str + left) = *(str + end);
//		*(str + end) = temp;
//		left++;
//		end--;
//	}
//}
//int main()
//{
//	char arr[] = "This is a student";
//	int left = 0;
//	int right = 0;
//	int end = strlen(arr) - 1;
//	reserve(arr, left, end);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void reserve(char* str, int left, int end)
//{
//	char temp = 0;
//	while (left < end)
//	{
//		temp = *(str + left);
//		*(str + left) = *(str + end);
//		*(str + end) = temp;
//		left++;
//		end--;
//	}
//}
//int main()
//{
//	char arr[] = "This is a student";
//	int left = 0;
//	int right = 0;
//	char* temp = arr;
//	int end = strlen(arr) - 1;
//	reserve(arr, left, end);
//	while (*temp != '\0')
//	{
//		left = right;
//		while (*temp != ' ' && *temp != '\0')
//		{
//			right++;
//			temp++;
//		}
//		reserve(arr, left, right - 1);
//		if (temp != '\0')
//		{
//			temp++;
//		}
//		right++;
//	}
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}