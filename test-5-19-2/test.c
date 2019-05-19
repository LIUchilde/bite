#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a = 10;
//	int b = a >> 1;
//	printf("%d\n", b);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a = 1;
//	int b = a++;
//	int c = ++a;
//	int d = a--;
//	int e = --a;
//	printf("%d %d %d %d\n", b, c, d, e);
//	system("pause"); 
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	float a = 3.14;
//	int num = 0;
//	num = (int) a;
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a = 10;
//	int b = 0;
//	if (a > 5)
//	{
//		b = 3;
//	}
//	else b = -3;
//	printf("%d", b);
//	system("pause\n");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a = 10;
//	int b = 0;
//	b = a > 5 ? 3 : -3;
//	printf("%d\n", b);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);
	printf("c=%d\n", c);
	system("pause");
	return 0;
}


 