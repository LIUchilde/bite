#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int num = 10;
//	int arr[10] = { 0 };
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)
//	{
//		int i = 0;
//		for (i = 0;i < num;i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//  system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int* p;
//	p = (int*)malloc(INT_MAX / 4);
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		*p = 20;
//	}
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0;i < 10;i++) // ��ֹԽ�����
//	{
//		*(p + i) = 0;
//	}
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//���ܶԷǶ�̬�����ڴ�ʹ��free�ͷţ�����ᵼ�³������
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int *p = (int*)malloc(10 * sizeof(int));
//	p++;
//	free(p);//p����ָ��̬�ڴ����ʼλ�á�����ʹ��free�ͷ�һ�鶯̬�ڴ濪�ٵ�һ���֣��������������
//	p = NULL;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	free(p);
//	free(p);//�ظ��ͷ�
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		*p = 20;
//	}
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void GetMemory(char **p)
//{
//	*p = (char*)malloc(100);
//}
//void test()
//{
//	char *str = "hello word";
//	GetMemory(&str);
//	strcpy(str, "hellow word");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void* GetMemory()
//{
//	static char p[] = "hello word";
//	return p;
//}
//void test()
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void test()
//{
//	char* str = (char*)malloc(100);
//	if (str != NULL)
//	{
//		strcpy(str, "hello word");
//	}
//	free(str);
//	//str = NULL;
//	str = (char*)malloc(100);
//	if (str != NULL)
//	{
//		strcpy(str, "hello word");
//		printf(str);
//	}
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    int* p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		for (int i = 0;i < 10;i++)
//		{
//			*(p + i) = 0;
//			printf("%p ", p);
//		}
//	}
//		free(p);
//		p = NULL;
//		system("pause");
//		return 0;
//}
