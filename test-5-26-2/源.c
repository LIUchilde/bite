#define  _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a = 128;
//	unsigned char b =128;
//	unsigned char c = -128;
//	printf("a=%u,b=%u,c=%u", a,b,c);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	system("pause");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char i = -1;
//	unsigned char j = 1;
//	printf("%d\n", i + j);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = -20;
//	unsigned int j =-10;
//	printf("%d\n", i + j);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//unsigned int i;
//for (i = 9;i >= 0;i--)
//{
//	printf("%u\n", i);
//}
//system("pause");
//return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a[1000];
//	int i = 0;
//	for (i = 0;i < 1000;i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d\n", a[i]);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//unsigned char i = 0;
//int main()
//{
//	for (i = 0;i <= 255;i++)
//	{
//		printf("hehe\n");
//	}
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 9;
	float *PFloat = (float*)& n;
	printf("n的值为：%d\n", n);
	printf("*PFloat的值为：%f\n", *PFloat);

	*PFloat = 9.0;
	printf("num的值为：%d\n", n);
	printf("*PFloat的值为：%f\n",*PFloat);
	system("pause");
	return 0;


}