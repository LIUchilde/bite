#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char str[] = "AbCdEf";
//	char c;
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		c = str[i];
//		if (c >= 'A' && c <= 'Z')
//		{
//			c = c + 32;
//		}
//		else if (c >= 'a' && c <= 'z')
//		{
//			c = c - 32;
//		}
//      printf("%c",c);
//		i++;
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char str[] = "AbCdEf";
//	char c;
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		c = str[i];
//		if (c >= 'A' && c<='Z' || c>='a' && c <= 'z')
//		{
//			c ^= 32;
//		}
//		printf("%c", c);
//		i++;
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char str[] = "AbCdEf";
	char c;
	int i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (isupper(c))
		{
			c = tolower(c);
		}
		else if (islower(c))
		{
			c = toupper(c);
		}
		printf("%c", c);
		i++;
	}
	printf("\n");
	system("pause");
	return 0;
}