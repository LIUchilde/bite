#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
//int main()
//{
//	char str[] = "This is a student";
//	char c;
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		c = str[i];
//		if (isupper(c))
//		{
//			c = tolower(c);
//		}
//		printf("%c", c);
//		i++;
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
//int main()
//{
//	char str[] = "AbCdEf";
//	char c;
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		c = str[i];
//		if (islower(c))
//		{
//			c = toupper(c);
//		}
//		printf("%c", c);
//		i++;
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	const char str1[] = "This is a student";
//	char str2[50];
//	memcpy(str2, str1, strlen(str1)+1);
//	printf("%s\n", str2);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char str1[] = "This is a student";
//	char str2[50];
//	memcpy(str2, str1 + 6, 6);
//	str2[6] = '\0';
//	printf("%s\n", str2);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char str1[] = "***";
//	char str2[] = "abcdef";
//	memcpy(str2, str1, strlen(str1));
//	printf("%s\n", str2);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
char* my_memcpy(char* dest, const char* src, int n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	if (pdest > psrc && pdest < psrc + n)
	{
		pdest = pdest + n - 1;
		psrc = psrc + n - 1;
		while (n)
		{
			*pdest-- = *psrc--;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*pdest++ = *psrc++;
			n--;
		}
	}
	return dest;
}
int main()
{
	char str1[] = "abcdefgh";
	char str2[] = "abcd";
	my_memcpy(str1 + 2, str2, strlen(str2));
	printf("%s\n", str1);
	system("pause");
	return 0;
}