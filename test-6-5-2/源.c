#define  _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//struct student
//{
//	long int num;
//	int age;
//	char* name;
//}st1 = { 200,18,"zhangsan" };
//struct student st2, st3;
//int main()
//{
//	printf("%ld,%d,%s\n", st1.num, st1.age, st1.name);
//	struct student st2 = { 300,21,"lisi" };
//	st3 = st2;
//	printf("%ld,%d,%s\n", st2.num, st2.age, st2.name);
//	printf("%ld,%d,%s\n", st3.num, st3.age, st3.name);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define Mon 1;
//#define Tues 2;
//#define Wed 3;
//#define Thur 4;
//#define Fri 5;
//#define Sat 6;
//#define Sun 7;
//int main()
//{
//	int day;
//	int n=scanf("%d", &day);
	//switch (day)
	//{
	//case 1:
	//	puts("Monday");
	//	break;
	//case 2:
	//	puts("Tuesday");
	//	break;
	//case 3:
	//	puts("Wednesday");
	//	break;
	//case 4:
	//	puts("Thursday");
	//	break;
	//case 5:
	//	puts("Friday");
	//	break;
	//case 6:
	//	puts("Saturday");
	//	break;
	//case 7:
	//	puts("Sunday");
	//	break;
	//}
	//system("pause");
	//return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	enum week { Mon = 1, Tues, Wed, Thur, Fri, Sat, Sun }day;
//	int n=scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		puts("Monday");
//		break;
//	case 2:
//		puts("Tuesday");
//		break;
//	case 3:
//		puts("Wednesday");
//		break;
//	case 4:
//		puts("Thursday");
//		break;
//	case 5:
//		puts("Friday");
//		break;
//	case 6:
//		puts("Saturday");
//		break;
//	case 7:
//		puts("Sunday");
//		break;
//	default:
//		puts("error");
//		break;
//	}
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	enum week { Mon = 1, Tues, Wed, Thur, Fri, Sat, Sun }day=Mon;
	printf("%d %d %d %d %d", sizeof(enum week), sizeof(Mon), sizeof(day), sizeof(Wed), sizeof(int));
	system("pause");
	return 0;
}