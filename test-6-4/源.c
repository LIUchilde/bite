#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//char* my_memmove(char* dest, const char* src, int n)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* pdest = (char*)dest;
//	char* psrc = (char*)src;
//	if (pdest > psrc && pdest < psrc + n)
//	{
//		*pdest = *pdest + n - 1;
//		*psrc = *psrc + n - 1;
//		while (n)
//		{
//			*pdest-- = *psrc--;
//			n--;
//		}
//	}
//	else
//	{
//		while (n)
//		{
//			*pdest++ = *psrc++;
//			n--;
//		}
//	}
//	return dest;
//}
//int main()
//{
//	char str1[] = "abcdefgh";
//	char str2[] = "abcd";
//	my_memmove(str1 + 2, str2, strlen(str2));
//	printf("%s\n", str1);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//char* my_strstr(char* dest, char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* pdest = (char*)dest;
//	char* psrc = (char*)src;
//	char* ptr=NULL;
//	while (*pdest != '\0')
//	{
//		if (*psrc != '\0' && *psrc == *pdest)
//		{
//			ptr = pdest;
//			pdest++;
//			psrc++;
//		}
//		pdest++;
//		if (ptr != '\0')
//		{
//			return ptr;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char str1[] = "this is a student";
//	char str2[] = "is";
//	printf("%s\n", my_strstr(str1, str2));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void reserve(char* str)
//{
//	int len=strlen(str);
//	char temp;
//	int i=0;
//	while (i<len/2)
//	{
//		temp = str[i];
//		str[i] = str[(len - 1 - i)];
//		str[(len - 1 - i)] = temp;
//		i++;
//	}
//	str[len] = '\0';
//}
//int main()
//{
//	char str[] = "this is a student";
//	reserve(str);
//	printf("%s\n", str);
//	system("pause");
//	return 0;
//}

