#define  _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Maxsize 100
typedef struct stack {
	int* top;//栈顶指针，一直在栈顶元素上一个位置
	int* base;//栈底指针，一直不变
	int stacksize;//栈可用的最大容量
}stack;
int length = 0;
//初始化函数
int Initstack(stack &s) {
	s.base = new int[Maxsize];//动态分配最大容量
	if (!s.base)
	{
		cout << "分配失败" << endl;
		return 0;
	}
	s.top = s.base;
	s.stacksize = Maxsize;
	return 1;
}
//入栈
int stackpush(stack& s, int val) {
	if (s.top - s.base == s.stacksize) {//栈满
		return 0;
	}
	else {
		(*s.top++) = val;
		length++;
	}
	return 1;
}
//出栈，用val返回
int stackpop(stack& s, int *val) {
	if (s.base == s.top) {//栈空
		return 0;
	}
	else {
		*val = *--s.top;//先减减，指向栈顶元素，再赋给val
		length--;
	}
	return 1;
}
//取栈顶
bool GetTop(stack& s, int* val) {
	if (s.base == s.top) {//栈空
		return false;
	}
	else{
		*val = *(s.top-1);
	}
	return true;
}
//判断栈中元素个数
int size(stack& s) {
	return length;
}
//判断栈是否为空
bool isEmpty(stack& s) {
	if (s.base == s.top) {//栈空
		return true;
	}
	else {
		return false;
	}
}
//销毁栈
int Destroystack(stack& s) {
	free(s.base);
	s.base = NULL;
	s.top = NULL;
	s.stacksize = NULL;
	return NULL;
}
void menu() {
	cout << "******1:入栈               2：:出栈******" << endl;
	cout << "****3**3:取栈顶             4：判断栈中元素个数" << endl;
	cout << "******5:判断栈是否为空     6：销毁栈" << endl;
	cout << "          **********7:退出**********" << endl;
}
void pushtostack(stack& s) {
	int n;
	int val;
	int flage;
	printf("请输入入栈元素个数：\n");
	int m=scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		printf("请输入第%d个值", i + 1);
		int m=scanf("%d", &val);
		flage = stackpush(s,val);
		if (flage) {
			printf("%d以入栈\n", val);
		}
		else {
			printf("栈以满！！！\n");
			break;
		}
	}
}
void popFromstack(stack& s) {
	int n;
	int va;
	int flage;
	printf("请输入出栈元素个数:\n");
	int m=scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		flage = stackpop(s, &va);
		if (flage) {
			printf("%d以出栈\n", va);
		}
		else {
			printf("栈以空！！！\n");
		}
	}
}
void GetTopofstack(stack& s) {
	bool flage;
	int va = 0;
	flage = GetTop(s, &va);
	if (flage) {
		printf("栈顶元素为%d\n", va);
	}
	else {
		printf("栈以空！！！\n");
	}
}
void sizeofstack(stack& s) {
	printf("栈中元素个数为：%d\n", length);
}
void isEmptystack(stack& s) {
	if (s.base==s.top) {
		printf("栈为空\n");
	}
	else {
		printf("栈不为空\n");
	}
}
int main() {
	stack s;
	int choice;
	Initstack(s);
	while (1) {
		menu();
		printf("请输入菜单序号：\n");
		int m=scanf("%d", &choice);
		if (choice == 7) {
			break;
		}
		switch(choice) {
		case 1:stackpush(s,1);break;
		case 2:popFromstack(s);break;
		case 3:GetTopofstack(s);break;
		case 4:sizeofstack(s);break;
		case 5:isEmptystack(s);break;
		case 6:Destroystack(s);
			break;
		default:printf("输入错误，请重新输入\n");
		}
	}
	system("pause");
	return 0;
}


