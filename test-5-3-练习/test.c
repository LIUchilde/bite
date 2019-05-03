#define  _CRT_SECURE_NO_WARNINGS 1

//µİ¹éÄæÖÃ×Ö·û´®
//#include<stdio.h>
//#include<stdlib.h>
//
//void fun(char* arr)
//{
//	int i = 0;
//	if (*arr != '\0')
//	{
//		arr ++;
//		fun(arr);
//		printf("%c", *(arr - 1));
//	}
//
//	
//}
//
//int main()
//{
//	char arr[5] = "0";
//	printf("ÇëÊäÈë×Ö·û´®\n");
//	scanf("%s", &arr);
//	 fun(arr);
//
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

int age(int n)
{
	int c = 0;
	if (n == 1)
	{
		c = 10;
	}
	else
	{
		c = age(n - 1)+2;
	}
	return c;
}

int main()
{
	int n = 0;
	age(n);

	printf("%d\n", age(5));
	system("pause");
	return 0;
}



 