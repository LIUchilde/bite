#define  _CRT_SECURE_NO_WARNINGS 0
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//char* my_strchr(char* str, char a)
//{
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		if (*str == a)
//		{
//			return str;
//		}
//		str++;
//	}
//	return 0;
//}
//int main()
//{
//	char arr[10] = "abcdcde";
//	char a=0 ;
//	printf("请输入要查找的字符:");
//	int n=scanf("%c",&a);
//	char* ret = my_strchr(arr, a);
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//char* my_strrchr(char* str, char a)
//{
//	char* ptr = NULL;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		
//		if (*str == a)
//		{
//			ptr = str;
//		}
//		str++;
//	}
//		if (ptr != 0)
//		{
//			return ptr;
//		}
// 	
//		return 0;
//}
//int main()
//{
//	char arr[] = "abcdcde";
//	char a = 0;
//	printf("请输入要查找的字符");
//	//scanf("%c", &a);
//	a = getchar();
//	printf("%s\n", my_strrchr(arr, a));
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char* my_strstr(char* str1, char* str2)
{
	char* ptr=NULL;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0')
	{
		ptr = str1;
		while (*str1 != '\0' && *str2 != '\0' && (*str1 == *str2))
		{
			str1++;
			str2++;
		}
		str1++;
		if (*str2 == '\0')
		{
			return ptr;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "i love you forever ";
	char arr2[] = "ve";
	printf("%s\n", my_strstr(arr1, arr2));
	system("pause");
	return 0;
}