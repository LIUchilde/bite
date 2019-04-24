#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
 

 void fun1(int i)
{
	if (i > 0)
	{
		fun1(i / 10);
		printf("%d ", i % 10);
		
	}
}
 int fun2(int i)
 {
	 if (i == 0)
	 {
		 return 0;
	 }
	 else
	 {
		 return i % 10 + fun2(i/10);
	 }
 }
	 int main()
	 {
		 int i = 0;
		 printf("请输入一个数\n");
		 scanf("%d", &i);
	     fun1(i);
		 int ret= fun2(i);
		 printf("\nret=%d\n", ret);
		 system("pause");
		 return 0;

	 }
	 
		 
		

	 
	








