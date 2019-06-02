#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "hello ");
//	strcpy(str2, "word");
//	strncat(str1, str2, 2);
//	puts(str1);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//char* my_strncat(char* pdest, const char* psrc, int n)
//{
//	char* start = pdest;
//	assert(pdest != NULL);
//	assert(psrc != NULL);
//	while (*pdest!='\0')
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
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "hello ");
//	strcpy(str2, "word");
//	printf("%s\n", my_strncat(str1, str2, 2));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "adc");
//	strcpy(str2, "acd");
//	int ret = 0;
//	 ret=strncmp(str1, str2, 2);
//	 if (ret < 0)
//	 {
//		 ret = -1;
//	 }
//	 else if (ret > 0)
//	 {
//		 ret = 1;
//	 }
//	 else
//		 ret;
//	 printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//int my_strncmp(char* pdest, char* psrc, int n)
//{
//	int ret = 0;
//	assert(pdest != NULL);
//	assert(psrc != NULL);
//	while (!(ret = (*pdest - *psrc) && *pdest != '\0' && *psrc != '\0' && n--))
//	{
//	    psrc++;
//	    pdest++;
//	}
//	if (ret < 0)
//	{
//		ret = -1;
//	}
//	if (ret > 0)
//	{
//		ret = 1;
//	}
//	return ret;
//}
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "abc");
//	strcpy(str2, "bcd");
//	printf("%d\n", my_strncmp(str1, str2, 2));
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
		while (str1 != '\0' && str2 != '\0' && (str1 == str2))
		{
			str1++;
			str2++;
		}
		str1++;
	}
	if (str2 == '\0')
	{
		return ptr;
	}
	return 0;
}
int main()
{
	char arr1[20];
	char arr2[20];
	strcpy(arr1, "i am a student");
	strcpy(arr2, "am");
	printf("%s\n", strstr(arr1,arr2));
	system("pause");
	return 0;
}
