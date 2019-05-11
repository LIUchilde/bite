#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	struct stu
//	{
//		char name[20];
//		char id[20];
//		short age;
//		float score;
//
//	};
//	struct stu s = { "zhangsan", "123456", 20, 55.5};
//	printf("%s %s %d %f", s.name, s.id, s.age, s.score);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//
//int main()
//{
//	struct stu
//	{
//		char name[20];
//		char id[20];
//		short age;
//		float score;
//	};
//	struct stu s = { "zhangsan", "12345", 20, 55.5 };
//	struct stu* ps = &s;
//	printf("%s %s %d %f\n", ps->name, ps->id, ps->age, ps->score);
//	system("pause");
//	return 0;
//}
 
//#include<stdio.h>
//#include<stdlib.h>
//struct stu
//{
//	char name[20];
//	char id[20];
//	short age;
//	float score;
//};
//struct stu s = { "zhangsan", "12345", 20, 55.5 };
//
//void print1(struct stu s)
//{
//	printf("%s %s %d %f\n", s.name, s.id, s.age, s.score);
//}
//void print2(struct stu* ps)
//{
//	printf("%s %s %d %f\n", ps->name, ps->id, ps->age, ps->score);
//}
//
//
//int main()
//{
//	print1(s);
//	print2(&s);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//	struct stu
//	{
//		char name[50];
//		int age;
//	};
//	struct stu fun(struct std[], int n);
//	int main()
//	{
//	
//		struct stu std[3] = { "zhangsan", 11 ,"lisi",12,"wangwu",13};
//		struct stu max;
//		max = *std;
//		int i = 0;
//		int n=3;
//		for (i = 0; i < n; i++)
//		{
//
//			if (max.age < std[i].age)
//			{
//				max = std[i];
//			}
//		}
//		printf("name:%s age:%d", max.name, max.age);
//		system("pause");
//		return 0; 
//
//	}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	struct stu
//	{
//		char name[20];
//		char id[20];
//		short age;
//		float score;
//
//	};
//	struct stu s = { "zhangsan", "123456", 20, 55.5};
//	strcpy(s.name, "lisi");
//	printf("%s %s %d %f", s.name, s.id, s.age, s.score);
//	printf("\n");
//	system("pause");
//	return 0;
//}




