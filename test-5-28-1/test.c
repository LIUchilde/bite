#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	char arr[] = "abc";
//	int ret= strlen(arr);
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//int my_strlen(char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abc";
//	int ret=my_strlen(arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[] = "hello word";
//	char arr2[20] ="0"
//	strcpy(arr2, arr1);
//	printf("%s\n %s", arr1, arr2);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//
//char* my_strcpy( char* pdest, const char* psre)
//{
//	char* start = pdest;
//	assert(pdest != NULL);
//	assert(psre != NULL);
//	while (*pdest = *psre)
//	{
//		pdest++;
//		psre++;
//	}
//	return start;
//}
//int main()
//{
//	char arr1[] = "hello word";
//	char arr2[20] = "0";
//    my_strcpy(arr2, arr1);
//	printf("%s\n",my_strcpy(arr2,arr1));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char arr1[20] = "abc";
//	char arr2[] = "def";
//	strcat(arr1, arr2);
//	printf("%s\n %s\n", arr1,arr2);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//char* my_strcat(char* pdest, char* psrc)
//{
//	char* start = pdest;
//	assert(pdest != NULL);
//	assert(psrc != NULL);
//	while (*pdest)
//	{
//		pdest++;
//	}
//	while (	*psrc);
//	{
//		*pdest++ = *psrc++;
//	}
//	return start;
//}
//
//int main()
//{
//	char arr1[20] = "abc";
//	char arr2[] = "def";
//	my_strcat(arr1, arr2);
//	printf("%s\n", my_strcat(arr1, arr2));
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int my_strcmp(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	int i = 0;
	int len;
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 > len2)
	{
		len = len1;
	}
	else
	{
		len = len2;
	}
	for (i = 0;i < len;i++)
	{
		if (arr1[i] == arr2[i] && arr1[i] != '\0')
		{
			continue;
		}
		if (arr1[i] < arr2[i])
		{
			return -1;
		}
		if ((arr1[i] == '\0') && (arr2[i] == '\0'))
		{
			return 0;
		}
		else
		{
			break;
		}
	}
	return 1;
}
int main()
{
	char arr1[] = "abc";
	char arr2[] = "defg";
	my_strcmp(arr1, arr2);
	printf("%d\n", my_strcmp(arr1, arr2));
	system("pause");
	return 0;	
}