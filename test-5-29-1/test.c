#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* my_strncpy(char* pdest, char* psrc, int n)
//{
//	char* start = pdest;
//	assert(pdest != NULL);
//	assert(psrc != NULL);
//	while (n)
//	{
//		*pdest++ = *psrc++;
//		n--;
//	}
//	*pdest = '\0';
//	return start;
//}
//int main()
//{
//	char arr1[] = "hello word";
//	char arr2[] = "0";
//	int len = sizeof(arr1) / sizeof(char);
//	printf("%s\n", my_strncpy(arr2, arr1,len));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//char* my_strncat(char* pdest, char* psrc, int n)
//{
//	char* start = pdest;
//	assert(pdest != NULL);
//	assert(psrc != NULL);
//	while (*pdest != '\0')
//	{
//		pdest++;
//	}
//	while (n)
//	{
//		*pdest++ = *psrc++;
//		n--;
//	}
//	*pdest = '\0';
//	return start;
//}
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[] = "word";
//	int len = sizeof(arr2) / sizeof(char);
//	printf("%s\n", my_strncat(arr1, arr2, len));
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int my_strncmp(char* pdest, char* psrc, int n)
{
	int ret = 0;
	assert(pdest != NULL);
	assert(psrc != NULL);
	while (!(ret = (*pdest - *psrc)) && *pdest != '\0' && n--)
	{
		pdest++;
		psrc++;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if(ret>0)
	{
		ret = 1;
	}
	return ret;
}
int main()
{
	char arr1[] = "abc";
	char arr2[] = "defg";
	printf("%d\n", my_strncmp(arr1, arr2,3));
	system("pause");
	return 0;
}