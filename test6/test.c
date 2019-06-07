#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void reserve(char* str, int start, int end)
//{
//	char temp;
//	while (start < end)
//	{
//		temp = *(start + str);
//		*(str + start) = *(str + end);
//		*(str + end) = temp;
//		start++;
//		end--;
//	}
//}
//int main()
//{
//	char arr[] = "i am a student";
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
//		if (*temp != '\0')
//		{
//			right++;
//			temp++;
//		}
//	}
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* replace(char* p)
//{
//	char* ret = p;
//	assert(p != NULL);
//	int num = 0;
//	int oldlen = 0;
//	int newlen = 0;
//	char* q = p;
//	char* r;
//	while (*p != '\0')
//	{
//		if (*p == ' ')
//		{
//			num++;
//		}
//		oldlen++;
//		p++;
//	}
//	q = p;
//	newlen = oldlen + 2 * num;
//	q = p + oldlen - 1;
//	r = p + newlen - 1;
//	while (q != r)
//	{
//		if (*q == ' ')
//		{
//			*r-- = '0';
//			*r-- = '2';
//			*r-- = '%';
//		}
//		else
//		{
//			*r = *q;
//			r--;
//		}
//		q--;
//	}
//	return ret;
//}
//int main()
//{
//	char p[] = "we are family";
//	printf("元字符串为:%s\n", p);
//	printf("替换后的字符串为：%s\n", replace(p));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void string_compress(char str[])
//{
//	int i=0;
//	int j = 0;
//	int count=0;
//	int len = strlen(str);
//	for (i = 0;i < len;i++)
//	{
//		count = 1;
//		while (str[i] == str[i + 1])
//		{
//			i++;
//			count++;
//		}
//		if (count > 1)
//		{
//			str[j] = count + '0';
//			j++;
//		}
//		str[j] = str[i];
//		j++;
//	}
//	str[j] = '\0';
//}
//int main()
//{
//	char str[] ="0";
//	printf("请输入一行字符串\n");
//	int n=scanf("%s", str);
//	 string_compress(str);
//	 printf("%s\n", str);
//	system("pause");
//	return 0;
//}


